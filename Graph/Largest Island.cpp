#include<bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
int dfs(int i, int j, vector<vector<int>> &grid, int n, int m){
    if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 1)return 0;
    grid[i][j] = 0;
    int cs = 1;
    for(int k = 0; k < 4; k++){
        cs += dfs(i + dx[k], j + dy[k], grid, n, m);
    }
    return cs;
}

int largest_island(vector<vector<int> > grid){
    int n = (int) grid.size(), m = (int) grid[0].size(), ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1){
              int ok = dfs(i, j, grid, n, m);
              ans = max(ans, ok);
            }
        }
    }
    return ans;
}
int main(){
    vector<vector<int> > grid = { 
  {1, 0, 0, 1, 0},
  {1, 0, 1, 0, 0},
  {0, 0, 1, 0, 1},
  {1, 0, 1, 1, 1},
  {1, 0, 1, 1, 0}};
  cout << largest_island(grid) << '\n';
}
