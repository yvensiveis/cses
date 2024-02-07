#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
 
using namespace std;
 
typedef long long int ll;
 
const int MAXN = 1e5 + 10, INF = 2e9, M = 1e9 + 7;
 
void solve() {
    int x, n; cin >> x >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    int k;
    for (int i = 0; i < n; i++) {
        cin >> k;
        q.push(k);
    }
    ll ans = 0;
    while (q.size() > 1)  {
        int a = q.top(); q.pop();
        int b = q.top(); q.pop();
        q.push(a+b);
        ans += a+b;
    }
    cout << ans << endl;
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
