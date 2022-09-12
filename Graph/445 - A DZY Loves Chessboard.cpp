#include<bits/stdc++.h>
using namespace std;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
void dfs(int i, int j, vector<vector<char>> &grid, int n, int m, int x, int y){
   if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != '.')return;
    if(grid[x][y] == 'B' or grid[x][y] == 'W') grid[i][j] = grid[x][y] ^ ('B' ^ 'W');
    else grid[i][j] = 'B';
    for(int k = 0; k < 4; k++){
      dfs(i + dx[k], j + dy[k], grid, n, m, i, j);
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
     cin.tie(0); 
     #ifndef ONLINE_JUDGE 
     freopen("input.txt","r",stdin); 
     freopen("output.txt","w",stdout); 
     #endif
     auto start=clock();
     int n, m;
     cin >> n >> m;
     vector<vector<char>> grid(n + 1, vector<char> (m + 1));
     for(int i = 0; i < n; i++){
      for(int j  = 0; j < m; j++){
         cin >> grid[i][j];
      }
     }
     for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
         if(grid[i][j] == '.'){
            dfs(i, j, grid, n, m, i, j);
          }
       }
     }
     for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
         cout << grid[i][j];
      }
      cout << '\n';
     }
     cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
     return 0;
}
