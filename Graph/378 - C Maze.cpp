#include<bits/stdc++.h>
using namespace std;

const int N = 505;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
vector<vector<char>> grid(N, vector<char> (N));
vector<vector<bool>> vis(N, vector<bool> (N, false));
int n, m, k;
bool valid(int x, int y){
  return x >= 0 and y >= 0 and x < n and y < m and grid[x][y] != '#' and !vis[x][y];
}

void dfs(int i, int j){
    vis[i][j] = true;
    for(int x = 0; x < 4; x++){
       if(valid(i + dx[x], j + dy[x])){
          if(!vis[i + dx[x]][j + dy[x]]){
            dfs(i + dx[x], j + dy[x]);
          }
       }
    }
    if(k) grid[i][j] = 'X', k--;
}

int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0); 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    #endif
    auto start=clock();
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        cin >> grid[i][j];
      }
    }
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(grid[i][j] == '.' and !vis[i][j]){
          dfs(i, j);
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
