#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define int long long
 
using namespace std;
 
const int maxn = 2e5 + 10, inf = 2e9, M = 1e9 + 7;
 
struct P {
	int x, y;
	void read() { cin >> x >> y; }
	bool operator<(P a) {
		return x > a.x;
	}
};
 
int pref[maxn], suff[maxn];
 
void solve() {
	int p, a, n; cin >> p >> a >> n;
	vector<P> v(n);
	for (int i = 0; i < n; ++i)
		v[i].read();
	if (p == 0) {
		sort(all(v), [](P lucca, P yvens) { return lucca.y > yvens.y; });
		int ans = 0;
		for (int i = 0; i < a; ++i)
			ans += v[i].y;
		cout << ans << endl;
		return;
	}
	sort(all(v));
 
	priority_queue<int> q;
	int cur = 0;
	for (int i = 0; i < p; ++i) {
		q.push(v[i].y - v[i].x);
		cur += v[i].x;
		pref[i] = cur;
	}
	for (int i = p; i < p+a; ++i) {
        // Considera pegar o i-ésimo cara como programador,
        // dai q.top() retorna o maior "lucro" trocando um dos
        // programadores atuais pra artista
		cur += q.top() + v[i].x; q.pop();
		pref[i] = cur;
		q.push({v[i].y - v[i].x});
	}
    
    // Suff serve pra pegar a soma dos maiores 
    // artistas que faltam
	q = priority_queue<int>();
	for (int i = n-1; i >= p+a; --i)
		q.push(v[i].y);
	cur = 0;
	for (int i = p+a-1; i >= p; --i) {
		q.push(v[i].y);
		cur += q.top(); q.pop();
		suff[i] = cur;
	}
 
	int ans = 0;
	for (int i = 0; i < n; ++i)
		ans = max(ans, pref[i] + suff[i+1]);
	cout << ans << endl;
}
 
signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}