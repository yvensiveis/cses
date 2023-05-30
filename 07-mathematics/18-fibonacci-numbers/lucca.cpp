#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define int long long
 
using namespace std;
 
const int maxn = 2e5 + 10, inf = 2e9, M = 1e9 + 7;
 
struct Matrix {
	int m[2][2];
	Matrix() {
		m[0][0] = m[1][1] = 1;
	}
	Matrix(int a, int b, int c, int d) {
		m[0][0] = a; m[0][1] = b;
		m[1][0] = c; m[1][1] = d;
	}
	Matrix operator*(Matrix b) {
		return Matrix(
			(m[0][0]*b.m[0][0] + m[0][1]*b.m[1][0])%M,
			(m[0][0]*b.m[0][1] + m[0][1]*b.m[1][1])%M,
			(m[1][0]*b.m[0][0] + m[1][1]*b.m[1][0])%M,
			(m[1][0]*b.m[0][1] + m[1][1]*b.m[1][1])%M
		);
	}
	Matrix operator^(int n) {
		if (n == 0) return Matrix();
		if (n == 1) return *this;
		Matrix res = *this ^ (n/2);
		res = res * res;
		if (n % 2) res = *this * res;
		return res;
	}
};
 
void solve() {
	int n; cin >> n;
	if (n == 0) {cout << "0\n"; return;}
	Matrix a(1, 1, 1, 0);
	a = a ^ (n-1);
	cout << a.m[0][0] << endl;
}
 
signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}