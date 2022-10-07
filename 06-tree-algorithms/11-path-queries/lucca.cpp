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
		tree[i] += x;
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
 
vector<int> adj[MAXN];
int tin[MAXN], tout[MAXN], v[MAXN], timer = -1; // -1 para 0-indexar
 
void dfs(int s, int p) {
	timer++;
	tin[s] = timer;
	for (int u : adj[s])
		if (u != p)
			dfs(u, s);
	tout[s] = timer;
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
	vector<int> nv(n);
	Segtree st(nv);
	for (int i = 1; i <= n; ++i) {
		st.update(tin[i], v[i]);
		st.update(tout[i]+1, -v[i]);
	}
	while (q--) {
		ll t, s, x;
		cin >> t >> s;
		if (t == 1) {
			cin >> x;
			st.update(tin[s], x-v[s]);
			st.update(tout[s]+1, -(x-v[s]));
			v[s] = x;
		} else {
			cout << st.query(0, tin[s]) << '\n';
		}
	}
}
 
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}