#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
 
using namespace std;
 
typedef long long int ll;
 
const int MAXN = 110, MAXS = 100*1000 + 10;
vector<int> v;
set<int> ans;
int n, memo[MAXN][MAXS];
 
bool dp(int i, int sum) {
    if (sum == 0) return true;
    if (i == n || sum < 0) return false;
    if (memo[i][sum] != -1) return memo[i][sum];
    bool a = dp(i+1, sum);
    bool b = dp(i+1, sum-v[i]);
    return memo[i][sum] = a || b;
}
 
void solve() {
    memset(memo, -1, sizeof(memo));
    cin >> n;
    v.resize(n);
    int tot = 0;
    for (int &x : v) {
        cin >> x;
        tot += x;
    }
    vector<int> ans;
    for (int i = 1; i <= tot; i++)
        if (dp(0, i))
            ans.pb(i);
    cout << ans.size() << endl;
    for (int x : ans) cout << x << ' '; cout << endl;
}
 
int main() {
    solve();
    return 0;
}