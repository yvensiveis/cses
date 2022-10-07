/**
* BFS em grid com reconstrucao do caminho
**/

#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 1010, dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
 
bool vis[MAXN][MAXN];
int dist[MAXN][MAXN];
pair<int, int> par[MAXN][MAXN];
char g[MAXN][MAXN];
 
int main() {
    int n, m, xa, ya, xb, yb; cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'A') xa = i, ya = j;
            else if (g[i][j] == 'B') xb = i, yb = j;
        }

    queue<pair<int, int>> q;
    q.push({xa, ya});
    vis[xa][ya] = true;
    dist[xa][ya] = 0;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dir[d][0], ny = y + dir[d][1];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (vis[nx][ny] || g[nx][ny] == '#') continue;
            dist[nx][ny] = dist[x][y] + 1;
            par[nx][ny] = {x, y};
            vis[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    cout << (vis[xb][yb] ? "YES" : "NO") << endl;
    if (vis[xb][yb]) {
        string ans = "";
        cout << dist[xb][yb] << endl;
        while (!(xa == xb && ya == yb)) {
            auto p = par[xb][yb];
            char move;
            for (int d = 0; d < 4; d++) {
                if (xb - p.first == dir[d][0] && yb - p.second == dir[d][1])
                    move = "DURL"[d];
            }
            ans += move;
            xb = p.first, yb = p.second;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    return 0;
}