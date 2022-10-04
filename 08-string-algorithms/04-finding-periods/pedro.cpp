#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int M = 1e9 + 9;
const int P = 31;

void solve() {
    string a; cin >> a;
    int n = a.size();

    vector<int> pfx_hash_array(n + 1);
    pfx_hash_array[0] = 0;

    vector<int> p(n + 1);
    p[0] = 1;
    for (int i = 1; i <= n; ++i) {
        p[i] = ((ll) p[i - 1] * P) % M;
    }

    for (int i = 1; i <= n; ++i) {
        int ch_hash = (a[i - 1] - 'a' + 1);
        pfx_hash_array[i] =
            (pfx_hash_array[i - 1] + ch_hash * (ll) p[i - 1]) % M;
    }

    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        bool b = true;
        for (int j = i; j < n; j += i) {
            int len = min(i, n - j);

            int pfx_hash =
                (pfx_hash_array[len] * (ll) p[j]) % M;

            int sub_hash =
                (pfx_hash_array[j + len] - pfx_hash_array[j] + M) % M;

            if (pfx_hash != sub_hash) {
                b = false;
                break;
            }
        }
        if (b) ans.push_back(i);
    }

    for (int ans_i : ans) cout << ans_i << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
