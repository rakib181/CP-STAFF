#include<bits/stdc++.h>
using namespace std;

vector<char> path;

bool valid(int x, int y, vector<vector<char>> &grid, int n, int m, vector<vector<bool>> &vis){
    if(x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == '#' || vis[x][y])return false;
    else return true;
}
bool bfs(int x, int y, int n, int m, vector<vector<char>> &grid, vector<vector<bool>> &vis, vector<vector<char>> &br){
     queue<pair<int, int>> q;
     q.push({x, y});
     vis[x][y] = true;

     while(!q.empty()){
        auto cur = q.front();
        int a = cur.first, b = cur.second;
        q.pop();

        if(grid[a][b] == 'B'){
          while(true){
            path.push_back(br[a][b]);

            if(path.back() == 'L')b++;
            if(path.back() == 'R')b--;
            if(path.back() == 'U')a++;
            if(path.back() == 'D')a--;

            if(a == x and b == y){
               break;
            }
          }
         return true;
        }
        if(valid(a, b - 1, grid, n, m, vis))br[a][b - 1] = 'L', q.push({a, b - 1}), vis[a][b - 1] = true;
        if(valid(a, b + 1, grid, n, m, vis))br[a][b + 1] = 'R', q.push({a, b + 1}), vis[a][b + 1] = true;
        if(valid(a - 1, b, grid, n, m, vis))br[a - 1][b] = 'U', q.push({a - 1, b}), vis[a - 1][b] = true;
        if(valid(a + 1, b, grid, n, m, vis))br[a + 1][b] = 'D', q.push({a + 1, b}), vis[a + 1][b] = true;
     }
     return false;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, x = 0, y = 0;
    cin >> n >> m;
    vector<vector<char>> grid(n + 1, vector<char> (m + 1)); bool c_f = false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A') x = i, y = j;
        }
    }
    vector<vector<bool>> vis(n + 1, vector<bool> (m + 1, false));
    vector<vector<char>> br(n + 1, vector<char> (m + 1));
    if(bfs(x, y, n, m, grid, vis, br)){
        reverse(path.begin(), path.end());
       cout << "YES" << '\n' << path.size() << '\n';
       for(auto x : path){
        cout << x;
       }
       cout << '\n';
    }else cout << "NO" << '\n';
    return 0;
}
