#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int orangesRotting(vector<vector<int>>  grid){
    int n = (int) grid.size(), m = (int) grid[0].size();
    vector<vector<int>> dist(n + 2, vector<int> (m + 2, inf));
    vector<vector<bool>> vis(n + 2, vector<bool> (m + 2, false));
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 2){
                int u = i, v = j;
                q.push({u, v});
                vis[u][v] = true;
                dist[u][v] = 0;
            }
        }
    }
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int x = it.first + dx[i], y = it.second + dy[i];
            if(x >= 0 and x < n and y >= 0 and y < m and grid[x][y] == 1 and !vis[x][y]){
                    q.push({x, y});
                    vis[x][y] = true;
                    dist[x][y] = min(dist[x][y], dist[it.first][it.second] + 1);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1){
                ans = max(ans, dist[i][j]);
            }
        }
    }
    return ans != inf ? ans : -1;
}

int main(){
    vector<vector<int>> grid = {
            {2, 1, 1}, {1, 1, 0}, {0, 1, 1}
    };
    cout << orangesRotting(grid) << '\n';
}
