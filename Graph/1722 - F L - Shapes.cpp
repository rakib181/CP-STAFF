#include<bits/stdc++.h>
using namespace std;

int n, m;
bool ok;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool valid(int x, int y, vector<vector<char>> &grid){
    return x >= 0 and y >= 0 and x < n and y < m and grid[x][y] == '*';
}
void dfs(int i, int j, vector<vector<char>> &grid, vector<pair<int, int>> &ind){
    if(!valid(i, j, grid))return;
    ind.emplace_back(i, j);
    grid[i][j] = '.';
    for(int k = 0; k < 8; k++){
        int x = i + dx[k], y = j + dy[k];
        dfs(x, y, grid, ind);
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--){
       cin >> n >> m;
       vector<vector<char>> grid(n + 1, vector<char> (m + 1));
       for(int i = 0; i < n; i++){
           for(int j = 0; j < m; j++){
               cin >> grid[i][j];
           }
       }
      for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++){
              vector<pair<int, int>> ind; ok = true;
              if(grid[i][j] == '*'){
                  dfs(i, j, grid, ind);
                  if(ind.size() != 3){
                      ok = false;
                      break;
                  }
                  set<int> c_x, c_y;
                  for(auto & x : ind){
                      c_x.insert(x.first);
                      c_y.insert(x.second);
                  }
                  if(c_x.size() != 2 or c_y.size() != 2){
                      ok = false;
                      break;
                  }
              }
          }
          if(!ok)break;
      }
     if(ok)cout << "YES" << '\n';
     else cout << "NO" << '\n';
    }
    return 0;
}
