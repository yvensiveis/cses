#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
 
using namespace std;
 
typedef long long int ll;
 
const int MAXN = 1e5 + 10, INF = 2e9, M = 1e9 + 7;
 
vector<ll> v;
 
int n, k;
 
bool check(ll x) {
	ll cur = 0, cnt = 1;
	for (int i = 0; i < n; i++) {
		if (cur + v[i] <= x) {
			cur += v[i];
		} else {
			cur = v[i];
			cnt++;
		}
	}
	return cnt <= k;
}
 
void solve() {
	cin >> n >> k;
	v.resize(n);
	ll tot = 0, max_el = 1;
	for (ll &x : v) {
		cin >> x;
		tot += x;
		max_el = max(max_el, x);
	}
	ll l = max_el, r = tot, ans = -1;
	while (l <= r) {
		ll mid = (l + r)/2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << ans << endl;
}
 
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}