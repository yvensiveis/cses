/**
 Ideia:
 * Usar um vetor auxiliar para guardar quanto foi
 * adicionado a cada elemento, inicialmente zerado
 * e ir atualizando ele conforme as queries do tipo
 * 1. Para queries do tipo 2, printar o valor original
 * do elemento + quanto ele foi adicionado.
 * Seg com o vetor auxiliar esquiva da necessidade de lazy.
**/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long int ll;

const int MAXN = 1e5 + 10, INF = 2e9, M = 1e9 + 7;

struct Segtree {
    vector<ll> tree;
    int n;
    Segtree(vector<ll> v) {
        n = v.size();
        while (__builtin_popcount(n) != 1) {
            v.pb(0LL);
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
    ll query(int node, int nl, int nr, int ql, int qr) {
        if (nl > qr || nr < ql) return 0LL;
        if (ql <= nl && nr <= qr) return tree[node];
        int k = (nl+nr)/2;
        return query(2*node, nl, k, ql, qr) +
               query(2*node+1, k+1, nr, ql, qr);
    }
    ll query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};

void solve() {
    int n, q; cin >> n >> q;
	vector<int> v(n);
	for (int &x : v) cin >> x;
	vector<ll> z(n);
	Segtree st(z);
	int t, a, b, u;
	while (q--) {
		cin >> t;
		if (t == 1) {
			cin >> a >> b >> u;
			st.update(a-1, u);
			if (b < n)
				st.update(b, -u);
		} else {
			cin >> a;
			cout << v[a-1] + st.query(0, a-1) << endl;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}