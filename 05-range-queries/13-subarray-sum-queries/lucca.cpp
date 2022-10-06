/* Queries de Kadane e update em ponto */
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
 
using namespace std;
 
typedef long long int ll;
 
const int MAXN = 1e5 + 10, M = 1e9 + 7, INF = 2e9;
 
struct Node {
	ll ans, sum, pref, suff;
	Node() {}
	Node(int x) {
		ans = sum = pref = suff = x;
	}
	Node(ll a, ll b, ll c, ll d) {
		ans = a; sum = b; pref = c; suff = d;
	}
	Node operator+(Node b) {
		return Node(
			max({ans, b.ans, suff + b.pref}),
			sum + b.sum,
			max(pref, sum + b.pref),
			max(b.suff, suff + b.sum)
		);
	}
};
 
struct Segtree {
	vector<Node> tree;
	int n;
	Segtree(vector<int> v) {
		n = v.size();
		while (__builtin_popcount(n) != 1) {
			v.pb(0);
			++n;
		}
		tree.resize(2*n);
		for (int i = 0; i < n; ++i)
			tree[i+n] = Node(v[i]);
		for (int i = n-1; i >= 1; --i)
			tree[i] = tree[2*i] + tree[2*i+1];
	}
	void update(int i, int x) {
		i += n;
		tree[i] = Node(x);
		for (int j = i/2; j != 0; j /= 2)
			tree[j] = tree[2*j] + tree[2*j+1];
	}
	void show() {
		for (int i = 0; i < n; ++i)
			cout << i << ' ' << tree[i+n].ans << endl;
	}
};
 
void solve() {
	int n, m; cin >> n >> m;
	vector<int> v(n);
	for (int &x : v) cin >> x;
	Segtree st(v);
	while (m--) {
		int k, x; cin >> k >> x;
		st.update(k-1, x);
		cout << max(st.tree[1].ans, 0LL) << '\n';
	}
}
 
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}