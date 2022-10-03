#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
 
using namespace std;
 
typedef long long int ll;
 
const int MAXN = 1e5 + 10, INF = 2e9, M = 1e9 + 7;
 
int n;

struct Segtree {
    vector<int> tree;
    int n;
    Segtree() {}
    Segtree(vector<int> v) {
        n = v.size();
        while (__builtin_popcount(n) != 1) {
            v.pb(0);
            n++;
        }
        tree.resize(2*n);
        for (int i = 0; i < n; ++i)
            tree[n+i] = tree[i];
        for (int i = n-1; i != 0; --i)
            tree[i] = tree[2*i] + tree[2*i+1];
    }
    int query(int node, int nl, int nr, int ql, int qr) {
        if (ql <= nl && nr <= qr) return tree[node];
        if (ql > nr || qr < nl) return 0;
        int k = (nl + nr)/2;
        return query(2*node, nl, k, ql, qr) + 
               query(2*node+1, k+1, nr, ql, qr);
    }
    int query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
    void update(int i, int x) {
        i += n;
        tree[i] = x;
        for (int j = i/2; j != 0; j /= 2)
            tree[j] = tree[2*j] + tree[2*j + 1];
    }
};

Segtree st;

int bb(int x) {
    int l = 0, r = n-1;
    while (l <= r) {
        int mid = (l+r)/2;
        int pos = mid + 1 - st.query(0, mid);
        if (pos == x) {
            if (st.tree[mid+st.n]) {
                r = mid - 1;
                continue;
            } else {
                return mid;
            }
        }
        if (pos > x) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

void solve() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<int> v(n);
    st = Segtree(v);
    for (int &x : v) cin >> x;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        int pos = bb(x);
        st.update(pos, 1);
        cout << v[pos] << ' ';
    }
    cout << endl;
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}