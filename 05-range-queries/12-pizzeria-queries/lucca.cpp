/**
 * Se estamos no predio k, o custo para
 * comprar uma pizza do predio i e:
 *  c(i) = p[i] + |i - k|
 * Queremos minimizar c(i).
  * Note que, se i > k:
  *  c(i) = p[i] + i - k
  * Logo, queremos minimizar p[i] + i
  * Ja se i < k:
  *  c(i) = p[i] + k - i = p[i] - i + k
  * Logo, queremos minimizar p[i] - i
 * Assim, guardamos para cada no da segtree
 * p[i] + i e p[i] - i
 OBS:
 * Nao esquecer de considerar o proprio predio k
**/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount

using namespace std;

typedef long long int ll;

const int MAXN = 1e5 + 10, M = 1e9 + 7;
const ll INF = 1e18;

struct Node {
    ll min_sum, min_diff;
    Node() {}
    Node(ll a, ll b) {
        if (!a || !b) min_sum = min_diff = INF;
        else min_sum = a, min_diff = b;
    }
    Node operator+(const Node& b) const {
        return Node(
            min(min_sum, b.min_sum),
            min(min_diff, b.min_diff)
        );
    }
};

struct Segtree {
    vector<Node> tree;
    int n;
    Segtree(vector<int>& v) {
        n = v.size();
        while (pc(n) != 1) {
            v.pb(0);
            ++n;
        }
        tree.resize(2*n);
        for (int i = 0; i < n; ++i)
            tree[i+n] = v[i] ? Node(v[i] + (i+1), v[i] - (i+1)) : Node(0, 0);
        for (int i = n-1; i >= 1; --i)
            tree[i] = tree[2*i] + tree[2*i+1];
    }
    void update(int i, int x) {
        tree[i+n] = Node(x + (i+1), x - (i+1));
        i += n;
        for (int j = i/2; j != 0; j /= 2)
            tree[j] = tree[2*j] + tree[2*j + 1];
    }
    Node query(int node, int nl, int nr, int ql, int qr) {
        if (nl > qr || nr < ql) return Node(0, 0);
        if (ql <= nl && nr <= qr) return tree[node];
        int k = (nl+nr)/2;
        return query(2*node, nl, k, ql, qr) +
               query(2*node+1, k+1, nr, ql, qr);
    }
    Node query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for (int &x : v) cin >> x;
    Segtree st(v);
    while (q--) {
        int t, a, b; cin >> t >> a; a--;
        if (t == 1) {
            cin >> b;
            v[a] = b;
            st.update(a, b);
        } else {
            Node right = st.query(a+1, n);
            Node left = st.query(0, a-1);
            cout << min({(ll)v[a], right.min_sum - (a+1), left.min_diff + (a+1)}) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}