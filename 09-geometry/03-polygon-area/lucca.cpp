/**
 * Basta calcular a norma do produto 
 * vetorial dos vetores correspondentes
 * aos pontos adjacentes. O sinal do
 * produto corrige a resposta para poligonos
 * não convexos
 OBS:
 * Não esquecer de tirar o modulo ao final.
**/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long int ll;

const int MAXN = 1e5 + 10, INF = 2e9, M = 1e9 + 7;

struct P {
	int x, y;
	void read() { cin >> x >> y; }
	ll operator*(P b) const {
		return 1LL*x*b.y - 1LL*b.x*y;
	}
	P operator-(P b) {
		return P{x-b.x, y-b.y};
	}
	ll triangle(P b, P c) {
		return (b - *this) * (c - *this);
	}
	bool operator<(P b) {
		return make_pair(x, y) < make_pair(b.x, b.y);
	}
	void show() {
		cout << x << ' ' << y << endl;
	}
};

void solve() {
	int n; cin >> n;
	vector<P> v(n);
	for (P &p : v) p.read();
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += v[i]*v[i+1 < n ? i+1 : 0];
	}
	cout << abs(ans) << endl;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}