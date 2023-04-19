#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount

using namespace std;

typedef long long int ll;

const int maxn = 2e5 + 10, inf = 2e9, M = 1e9 + 7;

void clear() {
}

bool vis[maxn];
int prufer[maxn], v[maxn], lst[maxn];

void solve() {
    clear();
    int n; cin >> n;
    for (int i = 0; i < n-2; ++i){
        cin >> prufer[i];
        vis[prufer[i]] = true;
        lst[prufer[i]] = i;
    }
    set<int> folhas;
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            folhas.insert(i);
    vector<pair<int, int>> edges;
    for (int i = 0; i < n-3; ++i) {
        edges.pb({prufer[i], *(folhas.begin())});
        folhas.erase(folhas.begin());
        if (lst[prufer[i]] == i)
            folhas.insert(prufer[i]);
    }
    edges.pb({*(folhas.begin()), prufer[n-3]});
    edges.pb({*(folhas.rbegin()), prufer[n-3]});
    for (auto [a, b] : edges) cout << a << ' ' << b << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // int t; cin >> t; while (t--)
    solve();
    return 0;
}