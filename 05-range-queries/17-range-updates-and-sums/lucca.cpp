/**
 Ideia:
 * O lazy de cada no eh um par (v, t) em que 
 * t eh o tipo da atualizacao (1 pra incrementar
 * e 2 pra setar) e v o valor a ser incrementado
 * ou setado
 OBS:
 * Tomar cuidado na implementacao do operator de
 * soma do lazy e na atualizacao do no no propagate
 * de acordo com o tipo do lazy
**/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount

using namespace std;

typedef long long int ll;

const int MAXN = 1e5 + 10, INF = 2e9, M = 1e9 + 7;

struct Lazy {
    ll v;
    int t;
    Lazy() { v = t = 0; }
    Lazy(ll v, ll t) { this->v = v; this->t = t; }
    void operator+=(Lazy b) {
        if (t == 0 || b.t == 2) {
            v = b.v, t = b.t;
            return;
        }
        v += b.v;
    }
};

struct Segtree {
    vector<ll> tree;
    vector<Lazy> lazy;
    int n;
    Segtree(vector<int>& v) {
        n = v.size();
        while (pc(n) != 1) {
            v.pb(0);
            ++n;
        }
        tree.resize(2*n);
        lazy.resize(2*n);
        for (int i = 0; i < n; ++i)
            tree[i+n] = v[i];
        for (int i = n-1; i >= 1; --i)
            tree[i] = tree[2*i] + tree[2*i+1];
    }
    void propagate(int node, int nl, int nr) {
        if (lazy[node].t == 0 || (lazy[node].t == 1 && lazy[node].v == 0)) return;
        if (lazy[node].t == 1) {
            tree[node] += (nr - nl + 1)*lazy[node].v;
        } else {
            tree[node] = (nr - nl + 1)*lazy[node].v;
        }
        if (nl < nr) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = {0, 0};
    }
    void update(int node, int nl, int nr, int ql, int qr, int x, int t) {
        propagate(node, nl, nr);
        if (nl > qr || nr < ql) return;
        if (ql <= nl && nr <= qr) {
            lazy[node] += Lazy(x, t);
            propagate(node, nl, nr);
            return;
        }
        int k = (nl+nr)/2;
        update(2*node, nl, k, ql, qr, x, t);
        update(2*node+1, k+1, nr, ql, qr, x, t);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    void update(int l, int r, int x, int t) { // t == 1: increase, t == 2: set
        update(1, 0, n-1, l, r, x, t);
    }
    ll query(int node, int nl, int nr, int ql, int qr) {
        propagate(node, nl, nr);
        if (nl > qr || nr < ql) return 0;
        if (ql <= nl && nr <= qr) return tree[node];
        int k = (nl+nr)/2;
        return query(2*node, nl, k, ql, qr) +
               query(2*node+1, k+1, nr, ql, qr);
    }
    ll query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
    void show() {
        for (int i = 0; i < n; ++i)
            cout << i << ": " << tree[i+n] << endl;
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for (int &x : v) cin >> x;
    Segtree st(v);
    while (q--) {
        int t, a, b, x;
        cin >> t >> a >> b;
        if (t == 3) {
            cout << st.query(a-1, b-1) << '\n';
        } else {
            cin >> x;
            st.update(a-1, b-1, x, t);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}