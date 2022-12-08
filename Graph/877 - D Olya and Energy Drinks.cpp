#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int inf = 1e12;
int n, m, k, sx, sy, dx, dy;

bool valid(int x, int y, vector<vector<char>> &grid, vector<vector<int>> &dist){
    return x >= 1 and x <= n and y >= 1 and y <= m and grid[x][y] != '#';
}

int BFS(vector<vector<char>> &grid){
    vector<vector<int>> dist(n + 1, vector<int> (m + 1, inf));
    queue<pair<int, int>> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;
    while (!q.empty()){
        auto it = q.front();
        q.pop();
        int x = it.first, y = it.second;
        for(int i = 1; i <= k; i++){
            if(!valid(x, y + i, grid, dist) or dist[x][y + i] < dist[x][y] + 1)break;
            if(dist[x][y + i] == inf){
               q.push({x, y + i});
               dist[x][y + i] = dist[x][y] + 1;
            }
        }
        for(int i = 1; i <= k; i++){
            if(!valid(x, y - i, grid, dist) or dist[x][y - i] < dist[x][y] + 1)break;
            if(dist[x][y - i] == inf){
                q.push({x, y - i});
                dist[x][y - i] = dist[x][y] + 1;
            }
        }
        for(int i = 1; i <= k; i++){
            if(!valid(x + i, y, grid, dist) or dist[x + i][y] < dist[x][y] + 1)break;
            if(dist[x + i][y] == inf){
                q.push({x + i, y});
                dist[x + i][y] = dist[x][y] + 1;
            }
        }
        for(int i = 1; i <= k; i++){
            if(!valid(x - i, y, grid, dist) or dist[x - i][y] < dist[x][y] + 1)break;
            if(dist[x - i][y] == inf){
                q.push({x - i, y});
                dist[x - i][y] = dist[x][y] + 1;
            }
        }
    }
    if(dist[dx][dy] == inf)return -1;
    else return dist[dx][dy];
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    vector<vector<char>> grid(n + 1, vector<char> (m + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> grid[i][j];
        }
    }
    cin >> sx >> sy >> dx >> dy;
    cout << BFS(grid) << '\n';
    return 0;
}
