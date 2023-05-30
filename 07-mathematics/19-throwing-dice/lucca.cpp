#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define int long long
 
using namespace std;
 
const int maxn = 2e5 + 10, inf = 2e9, M = 1e9 + 7;
 
struct Matrix {
    int n;
    vector<vector<int>> m;
    Matrix(int tam) {
        n = tam;
        m.resize(n);
        for (int i = 0; i < n; ++i) {
            m[i].resize(n);
            m[i][i] = 1;
        }
    }
    Matrix(int tam, int x) {
        n = tam;
        m.resize(n);
        for (auto &v : m) {
            v.resize(n);
            for (int &a : v)
                a = x;
        }
    }
    Matrix operator*(Matrix b) {
        Matrix res(n, 0);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                    res.m[i][j] = (res.m[i][j] + (m[i][k]*b.m[k][j])%M)%M;
        return res;
    }
    Matrix operator^(int b) {
        if (b == 0) return Matrix(n);
        if (b == 1) return *this;
        Matrix res = *this ^ (b/2);
        res = res * res;
        if (b % 2) res = *this * res;
        return res;
    }
};
 
void solve() {
    int n; cin >> n;
    const int p = 7;
    Matrix lucca(p, 0);
    for (int j = 0; j < p-1; ++j)
        lucca.m[0][j] = 1;
    for (int j = 1; j < p; ++j)
        lucca.m[j][j-1] = 1;
    lucca = lucca ^ n;
    cout << lucca.m[0][0] << endl;
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}