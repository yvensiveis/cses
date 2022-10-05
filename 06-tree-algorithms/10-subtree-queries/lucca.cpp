/**
 Ideia:
 * "Planarizar" a arvore em um vetor
 * no qual os nodes sao colocados de
 * acordo com a ordem de visita na DFS.
 * O tempo de entrada e de saida de cada
 * node corresponde ao range do vetor que
 * a subarvore dele representa.
 * Depois da planarizacao, se resume a update
 * em ponto e query em range, com seg ou BIT.
**/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount

using namespace std;

typedef long long int ll;

const int MAXN = 2e5 + 10, INF = 2e9, M = 1e9 + 7;

struct Segtree {
	vector<ll> tree;
	int n;
	Segtree(vector<int>& v) {
		n = v.size();
		while (pc(n) != 1) {
			v.pb(0);
			++n;
		}
		tree.resize(2*n);
		for (int i = 0; i < n; ++i)
			tree[i+n] = v[i];
		for (int i = n-1; i >= 0; --i)
			tree[i] = tree[2*i] + tree[2*i + 1];
	}
	void update(int i, int x) {
		i += n;
		tree[i] = x;
		for (int j = i/2; j != 0; j /= 2)
			tree[j] = tree[2*j] + tree[2*j + 1];
	}
	ll query(int node, int nl, int nr, int ql, int qr) {
		if (nl > qr || nr < ql) return 0;
		if (ql <= nl && nr <= qr) return tree[node];
		int k = (nl + nr)/2;
		return query(2*node, nl, k, ql, qr) +
			   query(2*node+1, k+1, nr, ql, qr);
	}
	ll query(int l, int r) {
		return query(1, 0, n-1, l, r);
	}
};

vector<int> adj[MAXN], nv;
int tin[MAXN], tout[MAXN], v[MAXN], cur = -1; // -1 para 0-indexar

void dfs(int s, int p) {
	cur++;
	tin[s] = cur;
	nv.pb(v[s]);
	for (int u : adj[s])
		if (u != p)
			dfs(u, s);
	tout[s] = cur;
}

void solve() {
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; ++i) cin >> v[i];
	for (int i = 0; i < n-1; ++i) {
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1, 1);
	Segtree st(nv);
	while (q--) {
		int t, s, x;
		cin >> t >> s;
		if (t == 1) {
			cin >> x;
			st.update(tin[s], x);
		} else {
			cout << st.query(tin[s], tout[s]) << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}