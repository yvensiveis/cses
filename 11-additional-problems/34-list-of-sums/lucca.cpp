#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount

using namespace std;

typedef long long int ll;

const int maxn = 2e5 + 10, inf = 2e9, M = 1e9 + 7;

vector<int> b;
int n, m;

vector<int> ok(int k) { // testa b[k] = a[1] + a[2]
    // b[0] = a[0] + a[1]
    // b[1] = a[0] + a[2]
    // -> a[0] = (b[0] + b[1] - b[k])/2
    vector<int> a(n);
    a[0] = b[0] + b[1] - b[k];
    if (a[0] <= 0 || a[0] % 2) return vector<int>();
    a[0] /= 2;
    a[1] = b[0] - a[0];
    a[2] = b[1] - a[0];
    multiset<int> ms;
    for (int i = 2; i < m; ++i)
        if (i != k)
            ms.insert(b[i]);
    // agora ms.begin() é a[0] + a[3]
    // ms[i] = a[i] + a[3]
    int i = 3;
    while (ms.size()) {
        a[i] = *ms.begin() - a[0];
        ms.erase(ms.begin());
        for (int j = 1; j < i; ++j) {
            if (!ms.count(a[j] + a[i]))
                return vector<int>();
            ms.erase(ms.find(a[j] + a[i]));
        }
        i++;
    }
    for (int j = 0; j < n; ++j)
        if (a[j] <= 0)
            return vector<int>();
    return a;
}

void solve() {
    cin >> n;
    m = n*(n-1)/2;
    b.resize(m);
    for (int &x : b) cin >> x;
    sort(all(b));
    for (int i = 2; i < m; ++i) {
        vector<int> lucca = ok(i);
        if (lucca.size()) {
            for (int x : lucca) cout << x << ' '; cout << endl;
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}