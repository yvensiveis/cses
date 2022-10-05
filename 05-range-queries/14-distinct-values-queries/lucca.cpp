/**
 Aplicacao direta de Mo.
 Detalhes:
 * k tem que ser escolhido com cuidado.
 * Compressao de coordenada pode dar TLE com map/set.
 * Nesse caso, trocar pra vector/array
**/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount

using namespace std;

typedef long long int ll;

const int MAXN = 2e5 + 10, INF = 2e9, M = 1e9 + 7;

const int k = 500; // sqrt(n) IMPORTANTE: deve ser grande  o suficiente

struct Query {
    int a, b, i, mo, ans;
    void read() { cin >> a >> b; mo = a/k; }
};

bool sort_by_index(Query a, Query b) {
    return a.i < b.i;
}

bool sort_by_range(Query a, Query b) {
    if (a.mo == b.mo) return a.b < b.b;
    return a.mo < b.mo;
}

map<int, int> comp;

int freq[MAXN], v[MAXN], cur;

void add(int x) {
    freq[x]++;
    if (freq[x] == 1) cur++;
}

void rem(int x) {
    freq[x]--;
    if (freq[x] == 0) cur--;
}

void solve() {
    int n, q; cin >> n >> q;
    set<int> aux;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        aux.insert(v[i]);
    }
    int helper = 0;
    for (int x : aux) comp[x] = helper++;
    for (int i = 1; i <= n; ++i) v[i] = comp[v[i]];
    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        queries[i].read();
        queries[i].i = i;
    }
    sort(all(queries), sort_by_range);
    int l = queries[0].a, r = queries[0].a;
    cur = 1;
    freq[v[l]]++;
    for (int i = 0; i < q; ++i) {
        int a = queries[i].a, b = queries[i].b;
        while (l < a) {
            rem(v[l]);
            l++;
        }
        while (l > a) {
            l--;
            add(v[l]);
        }
        while (r > b) {
            rem(v[r]);
            r--;
        }
        while (r < b) {
            r++;
            add(v[r]);
        }
        queries[i].ans = cur;
    }
    sort(all(queries), sort_by_index);
    for (Query qry : queries)
        cout << qry.ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}