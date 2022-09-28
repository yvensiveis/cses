/**
 * Aplicação direta de Convex-Hull
 OBS:
 * Tomar cuidado com * e **.
 * Checar se definição de convex hull inclui
 * pontos colineares.
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
	sort(all(v));
	vector<P> hull;
	for (int rep = 0; rep < 2; ++rep) {
		int s = hull.size();
		for (P c : v) {
			while (hull.size() - s >= 2) {
				P a = hull.end()[-2], b = hull.end()[-1];
				if (a.triangle(b, c) > 0) { // b está à direta da reta ac (>= para colinearidade)
					hull.pop_back(); // remove b
				} else {
					break;
				}
			}
			hull.pb(c);
		}
		hull.pop_back(); // *
		reverse(all(v)); // **
	}
	cout << hull.size() << endl;
	for (P p : hull) p.show();
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}