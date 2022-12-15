#include<bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void DFS(int x, int y, int n, int m, vector<vector<int>> &grid){
    grid[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(xx < 0 or xx >= n or yy < 0 or yy >= m or grid[xx][yy] != 0)continue;
        DFS(xx, yy, n, m, grid);
    }
}

int closedIsland(vector<vector<int>> grid) {
      int n = (int) grid.size(), m = grid[0].size();
      vector<vector<int>> new_grid = grid;
      for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
           if(i * j  == 0 or i == (int)grid.size() - 1 or j == (int)grid[i].size() - 1){
             if(new_grid[i][j] == 0)DFS(i, j, n, m, new_grid);
           }
        }
      }
      int cc = 0;
      for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(new_grid[i][j] == 0){
                cc++;
                DFS(i, j, n, m, new_grid);
            }
        }
      }
      return cc;  
}

int main(){
    vector<vector<int>> grid = {
        {1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}
    };
    cout << closedIsland(grid) << '\n';
}
