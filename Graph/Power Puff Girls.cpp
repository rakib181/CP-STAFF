#include <bits/stdc++.h>
using namespace std;
#define int long long int

class BREATH_FIRST_SEARCH{
public:
    int V{}, VV{};
    vector<vector<char>> g;
    vector<vector<bool>> vis;
    vector<vector<int>> dis;
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    void INIT(int _n, int _m){
        this -> V = _n;
        this -> VV = _m;
        g.resize(V, vector<char> (VV));
        vis.resize(V, vector<bool> (VV));
        dis.resize(V, vector<int> (VV));
        for(int i = 0; i < V; i++){
            for(int j = 0; j < VV; j++){
                g[i][j] = '\0';
                vis[i][j] = false;
                dis[i][j] = -1;
            }
        }
    }
    int BFS(pair<int, int> x_y, int x_d, int y_d, int n, int m){
        queue<pair<int, int>> q;
        q.push(x_y);
        vis[x_y.first][x_y.second] = true;
        dis[x_y.first][x_y.second] = 0;
        while (!q.empty()){
            auto it = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int xx = it.first + dx[i], yy = it.second + dy[i];
                if(xx < 1 or xx > n or yy < 1 or yy > m or g[xx][yy] == '#' or g[xx][yy] == 'm' or vis[xx][yy])continue;
                vis[xx][yy] = true;
                dis[xx][yy] = dis[it.first][it.second] + 1;
                q.push({xx, yy});
            }
        }
        return dis[x_d][y_d];
    }
}GP1, GP2, GP3;



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--) {
        cout << "Case " << cs++ << ": ";
        int n, m, x_d, y_d;
        cin >> n >> m;
        GP1.INIT(25, 25), GP2.INIT(25, 25), GP3.INIT(25, 25);
        vector<pair<int, int>> loc;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                 char ch;
                 cin >> ch;
                 GP1.g[i][j] = ch;
                 GP2.g[i][j] = ch;
                 GP3.g[i][j] = ch;
                 if(ch == 'h'){
                    x_d = i, y_d = j;
                 }
                 if(ch == 'a' or ch == 'b' or ch == 'c')loc.emplace_back(i, j);
            }
        }
        cout << max({GP1.BFS(loc[0], x_d, y_d, n, m), GP2.BFS(loc[1], x_d, y_d, n, m), GP3.BFS(loc[2], x_d, y_d, n, m)}) << '\n';
    }
    return 0;
}
