/**
    Ideia:
    * Bellman-ford com n iteracoes para definir se
    * ha ciclo de peso negativo. Se houver, reconstruir
    * ciclo com vetor de ancestrais.
    Observacao:
    * Se houver mais de um componente, convem adicionar
    * um node A com um aresta de peso 0 para todos os outros
    * nodes e tomar A como origem do Bellman-ford, para garantir
    * que todo o grafo eh processado.
**/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long int ll;

const int MAXN = 2550, M = 1e9 + 7;
const ll INF = 1e18;

ll dist[MAXN], par[MAXN];
bool vis[MAXN];

struct E {
    int a, b, w;
    void read() {
        cin >> a >> b >> w;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<E> edges(m);
    for (E &e : edges) e.read();
    for (int i = 2; i <= n; i++) dist[i] = INF;
    int start; // So eh util na n-esima iteração, para marcar um no afetado pelo ciclo
    for (int i = 0; i < n; i++) {
        start = 0;
        for (E e : edges) {
            if (dist[e.b] > dist[e.a] + e.w) {
                dist[e.b] = dist[e.a] + e.w;
                par[e.b] = e.a;
                start = e.b;
            }
        }
    }
    if (!start) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 0; i < n-1; i++) {
        start = par[start]; // Garante que start está no ciclo
    }
    vector<int> ans;
    ans.pb(start);
    int s = par[start];
    while (s != start) {
        ans.pb(s);
        s = par[s];
    }
    ans.pb(start);
    reverse(all(ans));
    for (int x : ans) cout << x << ' '; cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}