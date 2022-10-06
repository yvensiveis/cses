/* Query de maior soma de prefixo em 
   range e update em ponto */
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long int ll;

const int MAXN = 1e5 + 10, INF = 2e9, M = 1e9 + 7;

struct Node {
    ll ans, sum;
    Node operator+(Node b) {
        return Node{
            max(ans, sum + b.ans),
            sum + b.sum
        };
    }
    Node() { ans = sum = 0; }
    Node(int x) { ans = sum = x; }
    Node (ll a, ll b) { ans = a, sum = b; }
};

struct Segtree {
    vector<Node> tree;
    int n;
    Segtree(vector<int>& v) {
        n = v.size();
        while (__builtin_popcount(n) != 1) {
            v.pb(0);
            ++n;
        }
        tree.resize(2*n);
        for (int i = 0; i < n; ++i)
            tree[n+i] = Node(v[i]);
        for (int i = n-1; i >= 1; --i)
            tree[i] = tree[2*i] + tree[2*i+1];
    }
    void update(int i, int k) {
        i += n;
        tree[i] = Node(k);
        for (int j = i/2; j != 0; j /= 2)
            tree[j] = tree[2*j] + tree[2*j + 1];
    }
    Node query(int node, int nl, int nr, int ql, int qr) {
        if (nl > qr || nr < ql) return Node();
        if (ql <= nl && nr <= qr) return tree[node];
        int k = (nl+nr)/2;
        return query(2*node, nl, k, ql, qr) +
               query(2*node+1, k+1, nr, ql, qr);
    }
    Node query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for (int &x : v) cin >> x;
    Segtree st(v);
    while (q--) {
        int t, a, b; cin >> t >> a >> b;
        if (t == 1) {
            st.update(a-1, b);
        } else {
            cout << max(0LL, st.query(a-1, b-1).ans) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}