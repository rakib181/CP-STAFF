#include<bits/stdc++.h>
using namespace std;

const int N = 2590;
set<int> g[N];
vector <int> vis(N);
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

bool valid(int x, int y, int n, int m, char ch, vector<vector<char>> &grid){
    return x >= 1 and x <= n and y >= 1 and y <= m and grid[x][y] == ch;
}

bool DFS(int cur, int par){
    vis[cur] = 1;
    for(auto x : g[cur]){
        if(!vis[x]){
          bool sub = DFS(x, cur);
            if(sub)return true;
        }else if(x != par and vis[x] == 1){
            return true;
        }
    }
    vis[cur] = 2;
    return false;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n + 1, vector<char> (m + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> grid[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
           for(int k = 0; k < 4; k++){
               int x = i + dx[k], y = j + dy[k];
               if(valid(x, y, n, m, grid[i][j], grid)){
                   g[i * m + j].insert(x * m + y);
                   g[x * m + y].insert(i * m + j);
               }
           }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
                if (!vis[i * m + j]) {
                   bool cycle = DFS(i * m + j, -1);
                   if(cycle){
                       cout << "Yes" << '\n';
                       return 0;
                   }
                }
        }
    }
    cout << "No" << '\n';
    return 0;
}
