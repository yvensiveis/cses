/**
 * Aplicação direta de lazy propagation.
 * Tomar cuidado com indexacao do input e
 * com a atualizacao dos nos de acordo com
 * o lazy (varia com o tipo da seg);
**/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
 
using namespace std;
 
typedef long long int ll;
 
template<typename T> struct Segtree {
    vector<T> tree, lazy;
    int n;
    Segtree(vector<T> v) {
        n = v.size();
        while (__builtin_popcount(n) != 1) {
            v.pb(T());
            n++;
        }
        tree.resize(2*n);
        lazy.resize(2*n);
        for (int i = 0; i < n; ++i)
            tree[i+n] = v[i];
        for (int i = n-1; i >= 1; --i)
            tree[i] = tree[2*i] + tree[2*i+1];
    }
    void propagate(int node, int nl, int nr) {
        if (lazy[node] == T()) return;
        tree[node] += (nr - nl + 1) * lazy[node]; // Seg de somas
        if (nl < nr) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = T();
    }
    void update(int node, int nl, int nr, int ql, int qr, T x) {
        propagate(node, nl, nr);
        if (nl > qr || nr < ql) return;
        if (ql <= nl && nr <= qr) {
            lazy[node] += x;
            propagate(node, nl, nr);   
            return;
        }
        int k = (nl + nr)/2;
        update(2*node, nl, k, ql, qr, x);
        update(2*node+1, k+1, nr, ql, qr, x);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    void update(int l, int r, T x) {
        update(1, 0, n-1, l, r, x);
    }
    T query(int node, int nl, int nr, int ql, int qr) {
        propagate(node, nl, nr);
        if (nl > qr || nr < ql) return T();
        if (ql <= nl && nr <= qr) return tree[node];
        int k = (nl + nr)/2;
        return query(2*node, nl, k, ql, qr) +
               query(2*node+1, k+1, nr, ql, qr);
    }
    T query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};
 
void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for (ll &x : v) cin >> x;
    Segtree<ll> seg(v);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            a--; b--; // Input vem 1-indexado
            seg.update(a, b, u);
        } else {
            int k;
            cin >> k;
            k--; // Input vem 1-indexado
            cout << seg.query(k, k) << endl;
        }
    }
}
 
int main() {
    solve();
    return 0;
}