/**
Contar quantos subarrays tem soma k
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve() {
	int n, k; cin >> n >> k;
	map<ll, int> freq;
	ll sum = 0, ans = 0;
	freq[0] = 1;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		sum += x;
		ans += freq[sum-k];
		freq[sum]++;
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}