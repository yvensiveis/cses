/**
 Ideia:
 * Primeiro le as queries e comprime os
 * salarios e depois responde as queries
 OBS:
 * Compressao com map da TLE
**/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
 
using namespace std;
 
typedef long long int ll;
 
const int MAXN = 2e5 + 10, INF = 2e9, M = 1e9 + 7;
 
vector<int> comp;
 
int m = 0; // number of distinct salaries
 
struct Segtree {
    vector<int> tree;
    int n;
    Segtree(vector<int>& v) {
        n = v.size();
        while (__builtin_popcount(n) != 1) {
            v.pb(0);
            ++n;
        }
        tree.resize(2*n);
        for (int i = 0; i < n; ++i)
            tree[i+n] = v[i];
        for (int i = n-1; i >= 1; --i)
            tree[i] = tree[2*i] + tree[2*i+1];
    }
    void update(int i, int x) {
        i += n;
        tree[i] += x;
        for (int j = i/2; j != 0; j /= 2)
            tree[j] = tree[2*j] + tree[2*j+1];
    }
    int query(int node, int nl, int nr, int ql, int qr) {
        if (nl > qr || nr < ql) return 0;
        if (ql <= nl && nr <= qr) return tree[node];
        int k = (nl + nr)/2;
        return query(2*node, nl, k, ql, qr) +
               query(2*node+1, k+1, nr, ql, qr);
    }
    int query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
    void show() {
        for (int i = 0; i < n; ++i)
            cout << tree[i+n] << ' ';
        cout << endl;
    }
};
 
struct Query {
    int a, b; bool t; // 0: ?, 1: !
    void read() {
        char aux;
        cin >> aux >> a >> b;
        t = aux == '!';
    }
    void show() {
        cout << a << ' ' << b << ' ' << t << endl;
    }
};
 
int salary[MAXN];
 
int compress(int x) {
    return upper_bound(all(comp), x) - comp.begin();
}
 
void solve() {
    int n, q; cin >> n >> q;
    vector<int> v(n);
    set<int> aux;
    for (int &x: v) {
        cin >> x;
        comp.pb(x);
    }
    vector<Query> queries(q);
    for (Query &qry : queries) {
        qry.read();
        comp.pb(qry.a);
        comp.pb(qry.b);
    }
    sort(all(comp));
    comp.erase(unique(all(comp)), comp.end());
    m = comp.size() + 10;
    vector<int> freq(m);
    for (int i = 0; i < n; ++i) {
        salary[i+1] = compress(v[i]);
        freq[compress(v[i])]++;
    }
    Segtree st(freq);
    for (Query qry : queries) {
        if (qry.t) {
            st.update(salary[qry.a], -1);
            salary[qry.a] = compress(qry.b);
            st.update(salary[qry.a], +1);
        } else {
            cout << st.query(0, compress(qry.b)) - st.query(0, compress(qry.a)-1) << '\n';
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}