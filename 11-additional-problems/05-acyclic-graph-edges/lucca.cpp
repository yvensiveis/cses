#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define int long long
 
using namespace std;
 
const int maxn = 2e5 + 10, inf = 2e9, M = 1e9 + 7;
 
vector<int> adj[maxn];
 
void solve() {
	int n, m; cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		if (a < b) swap(a, b);
		cout << a << ' ' << b << endl;
	}
}
 
signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}