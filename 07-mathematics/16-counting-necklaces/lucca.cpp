/*
Burnside's Lemma
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define int long long
 
using namespace std;
 
const int maxn = 2e5 + 10, inf = 2e9, M = 1e9 + 7;
 
int fexp(int a, int b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	int res = fexp(a, b/2);
	res = (1LL*res*res)%M;
	if (b % 2) res = (1LL*res*a)%M;
	return res;
}
 
int inv(int x) {
	return fexp(x, M-2);
}
 
void solve() {
    int n, m; cin >> m >> n;
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		ans = (ans + fexp(n, __gcd(m, i))) % M;
	}
	cout << (1LL*ans*inv(m))%M << endl;
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // int t; cin >> t; while (t--)
    solve();
    return 0;
}