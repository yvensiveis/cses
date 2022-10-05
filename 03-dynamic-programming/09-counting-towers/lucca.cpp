#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
const int MAXN = 1e6 + 10, MAXM = 110, M = 1e9 + 7;
 
ll dp[MAXN][2];
 
ll phi(int i, bool j) {
    if (i == 1) return 1;
    ll& res = dp[i][j];
    if (res != -1) return res;
    if (j) return res = (4*phi(i-1, 1))%M + (phi(i-1, 0))%M;
    return res = (phi(i-1, 1)%M + (2*phi(i-1, 0))%M)%M;
}
 
void solve() {
    int n; cin >> n;
    cout << (phi(n, 0) + phi(n, 1))%M << endl;
}
 
int main() {
    memset(dp, -1, sizeof(dp));
    int t; cin >> t;
    while (t--) solve();
    return 0;
}