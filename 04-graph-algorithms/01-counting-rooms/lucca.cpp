/**
* Contar componentes em um grafo de grid
**/

#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 1010, dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
 
char g[MAXN][MAXN];
bool visited[MAXN][MAXN];
int n, m;
 
void dfs(int x, int y) {
    visited[x][y] = true;
    for (int d = 0; d < 4; d++) {
        int nx = x + dir[d][0], ny = y + dir[d][1];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (g[nx][ny] == '#' || visited[nx][ny]) continue;
        dfs(nx, ny);
    }
}
 
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            cin >> g[i][j];
    int cnt = 0;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            if (g[i][j] == '.' && !visited[i][j]) {
                cnt++;
                dfs(i, j);
            }
    cout << cnt << endl;
    return 0;
}