#include<bits/stdc++.h>
using namespace std;

const int N = 209, INF = INT_MAX;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
vector<vector<char>> grid(N, vector<char> (N));
vector<vector<int>> fire(N, vector<int> (N));
vector<vector<int>> jane(N, vector<int> (N));
vector<vector<bool>> vis(N, vector<bool> (N));

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
  return x < 1 || y < 1 || x > n || y > m;
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

int jane_bfs(cell j){
  reset_Vis();
  queue<cell> q;
  q.push(j);
  vis[j.x][j.y] = true;
  jane[j.x][j.y] = 0;

  while(!q.empty()){
    cell cur = q.front();
    q.pop();
    for(int i = 0; i < 4; i++){
      int x = cur.x + dx[i], y = cur.y + dy[i];
       
      if(escape(x, y)){
        return jane[cur.x][cur.y] + 1;
      }

      if(valid(x, y) and fire[x][y] > jane[cur.x][cur.y] + 1){
        jane[x][y] = jane[cur.x][cur.y] + 1;
        vis[x][y] = true;
        q.push({x, y});
      }
    }
  }
  return -1;
}


int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0); 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    #endif
    auto start=clock();
    int tt, idx = 1;
    cin >> tt;
    while(tt--){
      cout << "Case " << idx++ << ": ";
    cin >> n >> m;
     reset();
    vector<cell> f;
    cell jane;
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
         cin >> grid[i][j];
         if(grid[i][j] == 'J'){
            jane = {i, j};
         }
         else if(grid[i][j] == 'F'){
          f.push_back({i, j});
         }
      }
    }
    fire_bfs(f);
    int ans = jane_bfs(jane);
    if(ans == -1)cout << "IMPOSSIBLE" << '\n';
    else cout << ans << '\n';
    }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
