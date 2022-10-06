/**
Aplicacao direta de Kruskal/Prim
**/
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

int p[MAXN], sz[MAXN], n, m;

int find(int x) {
    while (x != p[x]) x = p[x];
    return x;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a), b = find(b);
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    p[b] = a;
}

ll kruskal(vector<E>& edges) {
    ll min_weight = 0;
    sort(all(edges));
    for (int i = 1; i <= n; ++i)
        p[i] = i, sz[i] = 1;
    for (E e : edges)
        if (!same(e.a, e.b)) {
            unite(e.a, e.b);
            min_weight += e.w;
        }
    return min_weight;
}

void solve() {
    cin >> n >> m;
    vector<E> edges(m);
    for (E &e : edges) e.read();
    ll ans = kruskal(edges);
    set<int> components;
    for (int i = 1; i <= n; ++i)
        components.insert(find(i));
    if (components.size() != 1)
        cout << "IMPOSSIBLE\n"; // Da pra checar se o numero de arestas usadas foi n-1
    else
        cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}