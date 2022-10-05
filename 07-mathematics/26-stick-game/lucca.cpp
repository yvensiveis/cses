#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
 
using namespace std;
 
typedef long long int ll;
 
const int MAXN = 1e6 + 10, INF = 2e9, M = 1e9 + 7;
 
int g[MAXN];
vector<int> p;
 
bool dp(int x) {
	if (g[x] != -1) return g[x];
	bool res = false;
	for (int s : p)
		if (x >= s && !dp(x-s))
			return g[x] = true;
	return g[x] = false;
}
 
void solve() {
	memset(g, -1, sizeof(g));
	int n, k; cin >> n >> k;
	p.resize(k);
	for (int &x : p) cin >> x;
	for (int i = 1; i <= n; i++)
		cout << (dp(i) ? 'W' : 'L');
	cout << endl;
}
 
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);	
	solve();
	return 0;
}