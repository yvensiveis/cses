#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef
    tree<
        int, null_type, less<int>,
        rb_tree_tag, tree_order_statistics_node_update
    >
    indexed_set;

void solve() {
    int n, k; cin >> n >> k;

    indexed_set a;
    for (int i = 1; i <= n; ++i) {
        a.insert(i);
    }

    int idx = 0;
    while (!a.empty()) {
        idx = (idx + k) % (int) a.size();
        auto it = a.find_by_order(idx);
        cout << *it << ' ';
        a.erase(it);
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
