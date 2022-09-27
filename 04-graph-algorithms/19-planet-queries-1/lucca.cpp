/**
 Aplicação direta de Binary lifting.
 OBS:
 * Tomar cuidado com a ordem dos for's no
 * preprocessamento de ancestrais;
 * Checar qual LOG é suficiente.
**/
#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int MAXN = 2e5+10, LOG = 31;

int par[MAXN][LOG];

int lift(int a, int b) {
	for (int i = LOG - 1; i >= 0; --i)
		if (b & (1 << i))
			a = par[a][i];
	return a;
}

void solve() {
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> par[i][0];
	for (int j = 1; j < LOG; ++j)
		for (int i = 1; i <= n; ++i)
			par[i][j] = par[par[i][j-1]][j-1];
	while (q--) {
	    int a, b; cin >> a >> b;
		cout << lift(a, b) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}