#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

struct DQ {
    ll max_n;
    vector<ll> dbb_arr;
    vector<ll> pow_10_arr;

    DQ(ll max_n_) {
        max_n = max_n_;

        ll dbb = 1;
        ll pow_10 = 1;
        ll p = 9;
        while (dbb <= max_n) {
            dbb_arr.push_back(dbb);
            dbb += p * (ll) dbb_arr.size();
            p = (p * 10LL);

            pow_10_arr.push_back(pow_10);
            pow_10 = (pow_10 * 10LL);
        }
    }

    int query(ll k) {
        auto it = upper_bound(dbb_arr.begin(), dbb_arr.end(), k);
        --it;
        ll dbb = *it;
        int digit_cnt = it - dbb_arr.begin() + 1;

        ll dist = k - dbb;
        ll inc = dist / digit_cnt;
        int p = dist % digit_cnt;
        ll num = pow_10_arr[digit_cnt - 1] + inc;

        string num_str = to_string(num);
        int res = num_str[p] - '0';

        return res;
    }
};

void solve() {
    DQ dq((ll) 1e18);

    int q; cin >> q;
    while (q--) {
        ll k; cin >> k;
        cout << dq.query(k) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
