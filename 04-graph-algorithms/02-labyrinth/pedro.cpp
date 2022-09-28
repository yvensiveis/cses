#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int MAXN = 1e3;
vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<char> dir_ch = {'U', 'R', 'D', 'L'};

int n, m;
string a[MAXN];

bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && (a[i][j] == '.' || a[i][j] == 'B');
}

string bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty()) {
        auto [ui, uj] = q.front(); q.pop();
        for (int k = 0; k < 4; ++k) {
            auto [di, dj] = dir[k];
            char dch = dir_ch[k];

            int ni = di + ui, nj = dj + uj;

            if (valid(ni, nj)) {
                if (a[ni][nj] == 'B') {
                    a[ni][nj] = dch;
                    int ri = ni, rj = nj;
                    string rev_ans;
                    while (a[ri][rj] != 'A') {
                        rev_ans.push_back(a[ri][rj]);
                        for (int l = 0; l < 4; ++l) {
                            if (dir_ch[l] == a[ri][rj]) {
                                auto [dri, drj] = dir[(l + 2) % 4];
                                ri += dri;
                                rj += drj;
                                break;
                            }
                        }
                    }
                    return rev_ans;
                }

                a[ni][nj] = dch;
                q.push({ni, nj});
            }
        }
    }
    return "";
}

void solve() {
    cin >> n >> m;
    for (string &ln : a) cin >> ln;

    int start_i = -1, start_j = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'A') {
                start_i = i;
                start_j = j;
                break;
            }
        }
    }

    string ans = bfs(start_i, start_j);
    int sz = ans.size();
    if (sz != 0) {
        reverse(ans.begin(), ans.end());
        cout << "YES\n" << sz << '\n' << ans << '\n';
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
