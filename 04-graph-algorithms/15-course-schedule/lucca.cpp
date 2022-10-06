/**
    Aplicacao direta de Ordenacao Topologica:
    * Adicionamos cada node sem dependencias a resposta
    * e diminuimos o numero de dependencias daqueles
    * que dependem dele, atualizando a fila de nodes
    * independentes.
    Complexidade:
    * O(n)
**/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long int ll;

const int MAXN = 1e5 + 10, INF = 2e9, M = 1e9 + 7;

vector<int> rev[MAXN];
int deg[MAXN];

void solve() {
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        rev[a].pb(b);
        deg[b]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (deg[i] == 0)
            q.push(i);
    vector<int> ans;
    while (!q.empty()) {
        int s = q.front(); q.pop();
        ans.pb(s);
        for (int u : rev[s]) {
            deg[u]--;
            if (deg[u] == 0)
                q.push(u);
        }
    }
    if (ans.size() != n) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (int s: ans)
        cout << s << ' ';
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}