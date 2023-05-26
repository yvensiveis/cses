/*
Ordena pelo fim do filme (guloso);
Preprocessa para cada tempo qual o próximo filme que
ele consegue ver;
Fica um grafo funcional, faz binary lifting para
achar o sucessor mais distante
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define int long long

using namespace std;

const int maxn = 2e5 + 10, maxv = 1e6 + 2, inf = 2e9, M = 1e9 + 7, LOG = 30;

struct Mv {
	int a, b;
	Mv() {}
	Mv(int x, int y) { a = x, b = y; }
	bool operator<(Mv p) {
		if (b == p.b) return a < p.a;
		return b < p.b;
	}
};

int nxt[maxn][LOG], t[maxv];

void solve() {
	int n, m; cin >> n >> m;
	vector<Mv> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i].a >> v[i].b;
	sort(all(v));

	for (int i = 0; i <= 1e6; ++i) t[i] = n;

	int cur = 1;
	for (int i = 0; i < n; ++i)
		while (cur <= v[i].a)
			t[cur++] = i;

	v.pb(Mv(1e6, 1e6));
	for (int i = 0; i <= n; ++i)
		nxt[i][0] = t[v[i].b];
	for (int j = 1; j < LOG; ++j)
		for (int i = 0; i <= n; ++i)
			nxt[i][j] = nxt[nxt[i][j-1]][j-1];

	while (m--) {
		int a, b; cin >> a >> b;
		int res = 0;
		a = t[a];
		if (v[a].b > b) {
			cout << "0\n";
			continue;
		}
		for (int i = LOG-1; i >= 0; --i) {
			if (v[nxt[a][i]].b <= b) {
				res += (1 << i);
				a = nxt[a][i];
			}
		}
		cout << res+1 << '\n';
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}