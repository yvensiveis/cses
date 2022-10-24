#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int MAXN = 1e5 + 10, INF = 2e9, M = 1e9 + 7;
 
void solve() {
	int n; cin >> n;
	int pos[n+1];
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		pos[x] = i;
	}
	int cnt = 1;
	for (int i = 2; i <= n; ++i)
		if (pos[i] < pos[i-1])
			cnt++;
	cout << cnt << endl;
}
 
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}