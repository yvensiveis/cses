#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
    int n; cin >> n;
    queue<int> q;
    for (int i = 1; i <= n; ++i) q.push(i);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        q.push(x);
        x = q.front(); q.pop();
        cout << x << ' ';
    }
    cout << '\n';
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
