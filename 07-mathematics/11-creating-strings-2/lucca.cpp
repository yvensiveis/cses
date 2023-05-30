/*
n!/(q1!q2!...qk!)
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define int long long
 
using namespace std;
 
const int maxn = 1e6 + 10, inf = 2e9, M = 1e9 + 7;
 
int fat[maxn];
 
void prep() {
	fat[0] = 1;
	for (int i = 1; i < maxn; ++i)
		fat[i] = (i*fat[i-1])%M;
}
 
int fexp(int a, int b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	int res = fexp(a, b/2);
	res = (res * res)%M;
	if (b%2) res = (res*a)%M;
	return res;
}
 
int inv(int x) {
	return fexp(x, M-2);
}
 
void solve() {
	string s; cin >> s;
	int freq[26] = {0};
	for (char ch : s)
		freq[ch - 'a']++;
	int n = s.size();
	int ans = fat[n];
	for (int i = 0; i < 26; ++i)
		if (freq[i])
			ans = (ans*inv(fat[freq[i]]))%M;
	cout << ans << endl;
}
 
signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	prep();
	solve();
	return 0;
}