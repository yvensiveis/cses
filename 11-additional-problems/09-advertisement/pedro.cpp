#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    set<int> levels;
    map<int, vector<int>> idx;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        idx[a[i]].push_back(i);
        levels.insert(a[i]);
    }

    ll ans = 0;

    multiset<int> rngs;
    rngs.insert(n);
    set<int> blocked;
    blocked.insert(-1);
    blocked.insert(n);

    for (int level : levels) {
        
        auto it = rngs.end();
        --it;
        int largest_rng = *it;
        ll area = (ll) level * largest_rng;
        ans = max(ans, area);

        for (int block : idx[level]) {
            auto it = blocked.upper_bound(block);
            int r = *it;
            --it;
            int l = *it;
            rngs.erase(rngs.find(r - l - 1));
            rngs.insert(block - l - 1);
            rngs.insert(r - block - 1);
            blocked.insert(block);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
