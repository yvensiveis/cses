#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount

using namespace std;

typedef long long int ll;

const int MAXN = 2e5 + 10, INF = 2e9, M = 1e9 + 7;

struct Segtree {
	vector<int> tree;
	int n;
	Segtree() {}
	Segtree(vector<int> v) {
		n = v.size();
		while (pc(n) != 1) {
			v.pb(0);
			++n;
		}
		tree.resize(2*n);
		for (int i = 0; i < n; ++i)
			tree[i+n] = v[i];
		for (int i = n-1; i >= 1; --i)
			tree[i] = tree[2*i] + tree[2*i + 1];
	}
	void update(int i, int x) {
		i += n;
		tree[i] += x;
		for (int j = i/2; j != 0; j /= 2)
			tree[j] = tree[2*j] + tree[2*j + 1];
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
};

struct HLD {
	vector<int> adj[MAXN];
	int sz[MAXN], pos[MAXN], pai[MAXN], head[MAXN], timer = 0, n;
	Segtree st;
	void setup(int s, int p=1) {
		sz[s] = 1;
		for (int& u : adj[s]) {
			if (u == p) continue;
			setup(u, s);
			sz[s] += sz[u];
			if (sz[u] > sz[adj[s][0]] || adj[s][0] == p)
				swap(adj[s][0], u);
		}
	}
	void build(int s, int p=1) {
		pos[s] = timer++;
		for (int u : adj[s]) {
			if (u == p) continue;
			pai[u] = s;
			head[u] = u == adj[s][0] ? head[s] : u;
			build(u, s);
		}
	}
	HLD(vector<pair<int, int>> edges) {
		n = edges.size() + 1;
		for (auto [a, b] : edges) {
			adj[a].pb(b);
			adj[b].pb(a);
		}
		setup(1);
		head[1] = 1;
		build(1);
		vector<int> v(n);
		this->st = Segtree(v);
	}
	void update(int a, int b) {
		if (pos[a] < pos[b]) swap(a, b);
		if (head[a] == head[b]) {
			st.update(pos[b], 1);
			st.update(pos[a]+1, -1);
			return;
		}
		st.update(pos[head[a]], 1);
		st.update(pos[a]+1, -1);
		update(pai[head[a]], b);
	}
	int query(int s) {
		return st.query(0, pos[s]);
	}
};

void solve() {
	int n, m; cin >> n >> m;
	vector<pair<int, int>> edges(n-1);
	for (int i = 0; i < n-1; ++i) {
		int a, b; cin >> a >> b;
		edges[i] = {a, b};
	}
	HLD hld(edges);
	while (m--) {
		int a, b; cin >> a >> b;
		hld.update(a, b);
	}
	for (int i = 1; i <= n; ++i)
		cout << hld.query(i) << ' ';
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}