#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount

using namespace std;

typedef long long int ll;

const int MAXN = 2e5 + 10, INF = 2e9, M = 1e9 + 7;

struct Segtree {
	int n;
	vector<ll> tree;
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

vector<int> adj[MAXN], v;
int val[MAXN], pai[MAXN], head[MAXN], sz[MAXN], pos[MAXN], timer=0, n;

struct HLD {
	Segtree st;
	void setup(int s, int p=1) {
		sz[s] = 1;
		for (int& u : adj[s]) {
			if (u == p) continue;
			setup(u, s);
			sz[s] += sz[u];
			if (sz[u] > sz[adj[s][0]] || adj[s][0] == p)
				swap(u, adj[s][0]);
		}
	}
	void build(int s, int p=1) {
		pos[s] = timer++;
		v[pos[s]] = val[s];
		for (int u : adj[s]) {
			if (u == p) continue;
			pai[u] = s;
			head[u] = u == adj[s][0] ? head[s] : u;
			build(u, s);
		}
	}
	HLD() {
		setup(1);
		head[1] = 1;
		v.resize(n);
		build(1);
		this->st = Segtree(v);
	}
	void update(int s, int x) {
		st.update(pos[s], x);
	}
	ll query(int a, int b) {
		if (pos[a] < pos[b]) swap(a, b);
		if (head[a] == head[b]) {
			return st.query(pos[b], pos[a]);
		}
		return st.query(pos[head[a]], pos[a]) + query(pai[head[a]], b);
	}
};

void solve() {
	int q; cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> val[i];
	for (int i = 0; i < n-1; ++i) {
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	HLD hld;
	while (q--) {
		int t, s, x;
		cin >> t >> s;
		if (t == 1) {
			cin >> x;
			hld.update(s, x);
		} else {
			cout << hld.query(1, s) << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}