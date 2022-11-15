#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> co_ordinate;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
void dfs(int i, int j, int n, vector<vector<int>> &grid, vector<vector<bool>> &vis){
   if(i < 0 or j < 0 or i >= n or j >= n or grid[i][j] == 0)return;
   if(vis[i][j])return;
   vis[i][j] = true;
   co_ordinate.push_back({i, j});
   dfs(i + 1, j, n, grid, vis);
   dfs(i - 1, j, n, grid, vis);
   dfs(i, j + 1, n, grid, vis);
   dfs(i, j - 1, n, grid, vis);
}

int shortestBridge(vector<vector<int>> grid){
    int n = grid.size();
    co_ordinate.clear();
    vector<vector<bool>> vis_old(n + 1, vector<bool> (n + 1, false)), vis_new(n + 1, vector<bool> (n + 1, false));
    vector<vector<int>> dist(n + 1, vector<int> (n + 1, 0)); bool done = false;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
         if(grid[i][j] == 1){
            dfs(i, j, n, grid, vis_old);
            done = true;
            break;
         }
      }
      if(done)break;
    }
    int ans = INT_MAX;
    queue<pair<int, int>> q;
    for(auto x : co_ordinate){
      vis_new[x.first][x.second] = true;
      q.push({x.first, x.second});
    }
    while(!q.empty()){
      auto it = q.front();
      q.pop();
      if(!vis_old[it.first][it.second] and grid[it.first][it.second] == 1){
         ans = min(ans, dist[it.first][it.second]);
         break;
      }
      for(int i = 0; i < 4; i++){
         int x = it.first + dx[i], y = it.second + dy[i];
         if(x >= 0 and y >= 0 and x < n and y < n and !vis_new[x][y]){
            vis_new[x][y] = true;
            q.push({x, y});
            dist[x][y] = dist[it.first][it.second] + 1;
         }
      }
    }
    return ans - 1;
}

int main(){
   vector<vector<int>> grid = {
       {0, 1, 0}, {0, 0, 0}, {0, 0, 1}
   };
   cout << shortestBridge(grid) << '\n';
}
