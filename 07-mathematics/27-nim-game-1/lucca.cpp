#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
 
using namespace std;
 
typedef long long int ll;
 
const int MAXN = 1e5 + 10, INF = 2e9, M = 1e9 + 7;
 
void solve() {
	int n, nim = 0; cin >> n;
	while (n--) {
		int x; cin >> x;
		nim ^= x;
	}
	cout << (nim ? "first\n" : "second\n");
}
 
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t; while (t--)
	solve();
	return 0;
}