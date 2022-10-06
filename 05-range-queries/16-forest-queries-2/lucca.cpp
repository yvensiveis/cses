/**
BIT 2D com update em ponto
e query sobre retangulo
**/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount

using namespace std;

typedef long long int ll;

const int MAXN = 1e3 + 10, INF = 2e9, M = 1e9 + 7;

int bit[MAXN][MAXN];
char grid[MAXN][MAXN];
 
void upd(int x, int y, int val) {
	for (int i = x; i < MAXN; i += (i & -i))
		for (int j = y; j < MAXN; j += (j & -j)) 
			bit[i][j] += val;
}
 
int sum(int x, int y) {
	int res = 0;
	for (int i = x; i > 0; i -= (i & -i))
		for (int j = y; j > 0; j -= (j & -j))
			res += bit[i][j];
	return res;
}

void solve() {
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			cin >> grid[i][j];
			if (grid[i][j] == '*')
				upd(i, j, 1);
		}
	int t, a, b, c, d;
	while (q--) {
		cin >> t >> a >> b;
		if (t == 1) {
			upd(a, b, grid[a][b] == '*' ? -1 : 1);
			grid[a][b] = grid[a][b] == '*' ? '.' : '*';
		} else {
			cin >> c >> d;
			cout << sum(c, d) + sum(a-1, b-1) - sum(c, b-1) - sum(a-1, d) << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}