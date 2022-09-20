#include<bits/stdc++.h>
using namespace std;
 
const int N = 1009, INF = INT_MAX;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
vector<vector<char>> grid(N, vector<char> (N));
vector<vector<int>> fire(N, vector<int> (N));
vector<vector<int>> jane(N, vector<int> (N));
vector<vector<bool>> vis(N, vector<bool> (N));
vector<vector<char>> br(N, vector<char> (N));
 
int n, m;
 
struct cell{
  int x;
  int y;
};
 
void reset(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            fire[i][j] = INF;
            jane[i][j] = INF;
        }
    }
}
 
void reset_Vis(){
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      vis[i][j] = false;
    }
  }
}
 
bool valid(int x, int y){
  return x >= 1 && y >= 1 && x <= n && y <= m && grid[x][y] != '#' && !vis[x][y];
}
 
bool escape(int x, int y){
  return x == 1 || y == 1 || x == n || y == m;
}
 
void fire_bfs(vector<cell> &f){
 
  reset_Vis();
  queue<cell> q;
 
  for(auto &x : f){
    q.push(x);
    vis[x.x][x.y] = true;
    fire[x.x][x.y] = 0;
  }
 
  while(!q.empty()){
    cell cur = q.front();
    q.pop();
 
    for(int i = 0; i < 4; i++){
      int x = cur.x + dx[i], y = cur.y + dy[i];
      if(valid(x, y)){
        fire[x][y] = fire[cur.x][cur.y] + 1;
        vis[x][y] = true;
        q.push({x, y});
      }
    }
  }
}
 
vector<char> jane_bfs(cell j){
  reset_Vis();
  queue<cell> q;
  q.push(j);
  vis[j.x][j.y] = true;
  jane[j.x][j.y] = 0;
 
  while(!q.empty()){
    cell cur = q.front();
    q.pop();
       
      if(escape(cur.x, cur.y)){
        vector<char> path;
        while(true){
        path.push_back(br[cur.x][cur.y]);
         if(path.back() == 'L')cur.y++;
            if(path.back() == 'R')cur.y--;
            if(path.back() == 'U')cur.x++;
            if(path.back() == 'D')cur.x--;
            if(grid[cur.x][cur.y] == 'A'){
              break;
            }
        }
        return path;
      }
 
      if(valid(cur.x, cur.y - 1) and fire[cur.x][cur.y - 1] > jane[cur.x][cur.y] + 1){
        jane[cur.x][cur.y - 1] = jane[cur.x][cur.y] + 1;
        vis[cur.x][cur.y - 1] = true;
        br[cur.x][cur.y - 1] = 'L';
        q.push({cur.x, cur.y - 1});
    }
       if(valid(cur.x, cur.y + 1) and fire[cur.x][cur.y + 1] > jane[cur.x][cur.y] + 1){
        jane[cur.x][cur.y + 1] = jane[cur.x][cur.y] + 1;
        vis[cur.x][cur.y + 1] = true;
        br[cur.x][cur.y + 1] = 'R';
        q.push({cur.x, cur.y + 1});
    }
       if(valid(cur.x - 1, cur.y) and fire[cur.x - 1][cur.y] > jane[cur.x][cur.y] + 1){
        jane[cur.x - 1][cur.y] = jane[cur.x][cur.y] + 1;
        vis[cur.x - 1][cur.y] = true;
        br[cur.x -1][cur.y] = 'U';
        q.push({cur.x - 1, cur.y});
    }
       if(valid(cur.x + 1, cur.y) and fire[cur.x + 1][cur.y] > jane[cur.x][cur.y] + 1){
        jane[cur.x + 1][cur.y] = jane[cur.x][cur.y] + 1;
        vis[cur.x + 1][cur.y] = true;
        br[cur.x + 1][cur.y] = 'D';
        q.push({cur.x + 1, cur.y});
    }
  }
  return {};
}
 
 
int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n >> m;
     reset();
    vector<cell> f;
    cell jane;
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
         cin >> grid[i][j];
         if(grid[i][j] == 'A'){
            jane = {i, j};
         }
         else if(grid[i][j] == 'M'){
          f.push_back({i, j});
         }
      }
    }
    if(escape(jane.x, jane.y)){
        cout << "YES" << '\n' << "0" << '\n';
        return 0;
    }
    fire_bfs(f);
    vector<char> ans = jane_bfs(jane);
    reverse(ans.begin(), ans .end());
    if(ans.size() == 0)cout << "NO" << '\n';
    else{
      cout << "YES" << '\n' << ans.size() << '\n';
     for(auto x : ans){
      cout << x;
     }
    cout << '\n';
    }
    return 0;
}
