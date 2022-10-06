/**
Contar quantos subarrays
tem soma divisivel por n.
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int MAXN = 1e5 + 10, INF = 2e9, M = 1e9 + 7;

map<int, ll> mod;

void solve() {
	int n; cin >> n;
	int sum = 0;
	ll ans = 0;
	mod[0] = 1;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		x %= n;
		sum = (sum + x + n)%n;
		ans += mod[sum];
		mod[sum]++;
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}