/**
 Ideia:
 * Hierholzer no grafo direcionado
 * em que cada vertice eh uma substring
 * binaria de tamanho n-1.
 * A resposta eh "0"*(n-1) + a string da
 * concatenacao das arestas
**/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
 
using namespace std;
 
typedef long long int ll;
 
const int MAXN = (1 << 15) + 10, MAXM = 2e5 + 10, M = 1e9 + 7, INF = 2e9;
 
vector<int> adj[MAXN];
 
int indeg[MAXN], outdeg[MAXN];
vector<int> path;
 
void hierholzer(int s) {
	while (outdeg[s]) {
		int u = adj[s].back();
		outdeg[s]--;
		indeg[u]--;
		adj[s].pop_back();
		hierholzer(u);
	}
	path.push_back(s);
}
 
void solve() {
	int n; cin >> n;
	int m = (1 << (n-1));
	for (int i = 0; i < m; ++i) {
		int a = (i << 1)&~m; // adiciona 0 ao final de i
        int b = a | 1; // adiciona 1 ao final de i
		adj[i].pb(a); adj[i].pb(b);
        outdeg[i] += 2;
		indeg[a]++, indeg[b]++;
	}
	hierholzer(0);
	reverse(all(path));
	string ans = ""; for (int i = 0; i < n-1; ++i) ans += "0";
	for (int i = 0; i < path.size()-1; ++i) {
		ans += (path[i+1] & 1) + '0'; // o ultimo bit de v eh caracter pego pra ir de u a v
	}
	cout << ans << endl;
}
 
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}