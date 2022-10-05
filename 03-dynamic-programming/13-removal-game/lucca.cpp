#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
 
using namespace std;
 
typedef long long int ll;
 
const int MAXN = 5010, INF = 2e9, M = 1e9 + 7;
 
ll v[MAXN], pref[MAXN], memo[MAXN][MAXN];
 
ll sum(int i, int j) { return pref[j+1] - pref[i]; }
 
ll dp(int i, int j) {
	if (i == j - 1) return max(v[i], v[j]);
	if (memo[i][j] != -1) return memo[i][j];
	return memo[i][j] = max(
		v[i] + sum(i+1, j) - dp(i+1, j),
		v[j] + sum(i, j-1) - dp(i, j-1)
	);
}
 
void solve() {
	memset(memo, -1, sizeof(memo));
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		pref[i+1] = pref[i] + v[i];
	}
	cout << dp(0, n-1) << endl;
}
 
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}