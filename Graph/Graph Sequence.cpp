#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

void dfs(int i, int j, int n, int m, vector<vector<int>> &matrix, vector<vector<bool>> &vis, vector<vector<int>> &cache){
    vis[i][j] = true;
    int ans = 0;
    for(int k = 0; k < 4; k++){
        int nx = i + dx[k], ny = j + dy[k];
        if(nx >= 0 and nx < n and ny >= 0 and ny < m and matrix[i][j] < matrix[nx][ny]){
            if(vis[nx][ny]){
                ans = max(ans, 1 + cache[nx][ny]);
            }else{
                dfs(nx, ny, n, m, matrix, vis, cache);
                ans = max(ans, 1 + cache[nx][ny]);
            }
        }
    }
    cache[i][j] = ans;
    return;
}


int longestPathSequence(vector<vector<int> > matrix){
     int n = matrix.size(), m = matrix[0].size(), ans = 0;
     vector<vector<int>> cache(n + 1, vector<int> (m + 1, 0));
     vector<vector<bool>> vis(n + 1, vector<bool> (m + 1, false));
     for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j]){
                dfs(i, j, n, m, matrix, vis, cache);
                ans = max(ans, cache[i][j]);
            }
        }
     }
    
    return ans + 1;
}

int main(){
    vector<vector<int>> matrix = 
  { 
  {0,  2,  4,  3,  2},
  {7,  6,  5,  5,  1},
  {8,  9,  7, 18, 14},
  {5, 10, 11, 12, 13},
  };
  cout << longestPathSequence(matrix) << '\n';

}
