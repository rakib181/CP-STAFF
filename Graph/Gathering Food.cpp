#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 15;
int n;
vector<vector<char>> g(N, vector<char> (N));
vector<vector<int>> dis(N, vector<int> (N));
vector<vector<bool>> vis(N, vector<bool> (N));
int dx[4] = {0,0, 1, -1}, dy[4] = {1, -1, 0, 0};
char des;

void INIT(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            vis[i][j] = false;
            dis[i][j] = 0;
        }
    }
}


int BFS(int &x, int &y){
    INIT();
   queue<pair<int, int>> q;
   q.push({x, y});
   vis[x][y] = true;
   dis[x][y] = 0;
   while(!q.empty()){
       auto it = q.front();
       q.pop();
       if(g[it.first][it.second] == des){
           x = it.first, y = it.second;
          return dis[it.first][it.second];
       }
       for(int i = 0; i < 4; i++){
           int xx = it.first + dx[i], yy = it.second + dy[i];
           if(xx < 0 or xx >= n or yy < 0 or yy >= n or g[xx][yy] == '#' or vis[xx][yy] or (g[xx][yy] > des and des <= 'Z')) {
               continue;
           }
                   q.push({xx, yy});
                   vis[xx][yy] = true;
                   dis[xx][yy] = dis[it.first][it.second] + 1;
       }
   }
    return -1;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--) {
        cout << "Case " << cs++ << ": ";
        cin >> n; int x, y, cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> g[i][j];
                if(g[i][j] == 'A')x = i, y = j;
                if(isupper(g[i][j])){
                    cnt++;
                }
            }
        }
        des = 'B';
        cnt--; int res = 0, cost = 0;
        for(int i = 0; i < cnt; i++){
            cost = BFS(x, y);
            if(cost == -1){
                cout << "Impossible" << '\n';
                break;
            }else{
                res += cost;
            }
            des++;
        }
        if(cost != -1) cout << res << '\n';
    }
    return 0;
}
