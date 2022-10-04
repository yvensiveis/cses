/**
 Ideia:
 * O lazy de cada no eh um par (v, cnt) em que 
 * v eh o primeiro valor a ser adicionado no range
 * e cnt eh o numero de operacoes.
 OBS:
 * Muito chato atualizar os lazys de cada cara
 * e usar o lazy pra atualizar o valor do node
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
    int cnt;
    Lazy() { v = cnt = 0; }
    Lazy(ll v, ll cnt) { this->v = v; this->cnt = cnt; }
    void operator+=(Lazy b) {
        v += b.v;
        cnt += b.cnt;
    }
};

ll sum(ll n) {
    return n*(n+1)/2;
}

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
        if (lazy[node].cnt == 0 || lazy[node].v == 0) return;
        tree[node] += (nr - nl + 1) * lazy[node].v + sum(nr-nl) * lazy[node].cnt;
        if (nl < nr) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += Lazy(lazy[node].v + ((nr - nl)/2 + 1)*lazy[node].cnt, lazy[node].cnt);
        }
        lazy[node] = Lazy(0, 0);
    }
    void update(int node, int nl, int nr, int ql, int qr) {
        propagate(node, nl, nr);
        if (nl > qr || nr < ql) return;
        if (ql <= nl && nr <= qr) {
            lazy[node] += Lazy(nl-ql+1, 1);
            propagate(node, nl, nr);
            return;
        }
        int k = (nl+nr)/2;
        update(2*node, nl, k, ql, qr);
        update(2*node+1, k+1, nr, ql, qr);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    void update(int l, int r) {
        update(1, 0, n-1, l, r);
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
        int t, a, b;
        cin >> t >> a >> b; a--, b--;
        if (t == 1) {
            st.update(a, b);
        } else {
            cout << st.query(a, b) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}