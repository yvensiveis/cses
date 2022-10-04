#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount

using namespace std;

typedef long long int ll;

const int MAXN = 1e5 + 10, INF = 2e9, M = 1e9 + 7;

struct Segtree {
    vector<int> tree;
    int n;
    Segtree(vector<int>& v) {
        while (pc(n) != 1) {
            n = v.size();
            v.push_back(0);
            n++;
        }
        tree.resize(2*n);
        for (int i = 0; i < n; i++)
            tree[n+i] = v[i];
        for (int i = n-1; i > 0; i--)
            tree[i] = max(tree[2*i], tree[2*i + 1]);
    }
    int query(int node, int nl, int nr, int ql, int qr) {
        if (nl > qr || nr < ql) return 0;
        if (ql <= nl && nr <= qr) return tree[node];
        int k = (nl + nr) / 2;
        return max(
            query(2*node, nl, k, ql, qr),
            query(2*node + 1, k+1, nr, ql, qr)
        );
    }
    int query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
    void update(int i, int x) {
        i += n;
        tree[i] += x;
        for (int j = i/2; j != 0; j /= 2)
            tree[j] = max(tree[2*j], tree[2*j + 1]);
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<int> v(n);
    for (int &x : v) cin >> x;
    Segtree st(v);
    while (m--) {
        int x; cin >> x;
        int l = 0, r = n-1, ans = -1;
        while (l <= r) {
            int mid = (l + r)/2;
            int q = st.query(0, mid);
            if (q >= x) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (ans == -1) {
            cout << "0 ";
            continue;
        }
        st.update(ans, -x);
        cout << ans + 1 << ' ';
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}