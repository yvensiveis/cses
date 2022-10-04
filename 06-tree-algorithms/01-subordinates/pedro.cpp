#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int MAX_N = 2e5 + 1;

vector<int> g[MAX_N];
int sub[MAX_N];

int dfs(int r) {
    if (sub[r] != 0) return sub[r];

    int res = 1;
    for (int x : g[r]) {
        res += dfs(x); 
    }

    return sub[r] = res;
}

void solve() {
    int n; cin >> n;
    for (int i = 2; i <= n; ++i) {
        int p; cin >> p;
        g[p].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; ++i) {
        cout << sub[i] - 1 << ' ';
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
