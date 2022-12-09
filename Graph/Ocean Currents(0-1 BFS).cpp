#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int inf = 1e12;
int n, m, sx, sy, dx, dy;
int DX[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, DY[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int Z_O_BFS(vector<vector<char>> &grid){
    vector<vector<int>> dist(n + 1, vector<int> (m + 1, inf));
    deque<pair<int, int>> dq;
    dq.emplace_back(sx, sy);
    dist[sx][sy] = 0;
    while (true){
        auto it = dq.front();
        dq.pop_front();
        int x = it.first;
        int y = it.second;
        if(x == dx and y == dy){
            return dist[dx][dy];
        }
        int co_x = x + DX[grid[x][y] - '0'], co_y = y + DY[grid[x][y] - '0'];
        if(co_x >= 0 and co_x < n and co_y >= 0 and co_y < m and (dist[co_x][co_y] == inf or dist[co_x][co_y] > dist[x][y])){
            dist[co_x][co_y] = dist[x][y];
            dq.push_front({co_x, co_y});
        }
        for(int i = 0; i < 8; i++){
            int n_x = x + DX[i], n_y = y + DY[i];
            if(n_x >= 0 and n_x < n and n_y >= 0 and n_y < m and (dist[n_x][n_y] == inf or dist[n_x][n_y] > dist[x][y] + 1)){
               dist[n_x][n_y] = dist[x][y] + 1;
               dq.emplace_back(n_x, n_y);
            }
        }
    }
    return -1;
}

int32_t main() {
    cin >> n >> m;
    vector<vector<char>> grid(n + 1, vector<char> (m + 1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    int tt;
    cin >> tt;
    while(tt--){
        cin >> sx >> sy >> dx >> dy;
        sx--, sy--, dx--, dy--;
        cout << Z_O_BFS(grid) << '\n';
    }
    return 0;
}
