#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long int ll;

const int MAXN = 1e5 + 10, INF = 2e9, M = 1e9 + 7;

struct E {
    int a, b, w;
    void read() { cin >> a >> b >> w; }
    bool operator<(const E& e) const {
        return w < e.w;
    }
};

int p[MAXN], sz[MAXN], n, m, cnt, max_sz;

int find(int x) {
    while (x != p[x]) x = p[x];
    return x;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    p[b] = a;
    cnt++;
    max_sz = max(max_sz, sz[a]);
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        p[i] = i, sz[i] = 1;
    while (m--) {
        int a, b; cin >> a >> b;
        unite(a, b);
        cout << n-cnt << ' ' << max_sz << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}