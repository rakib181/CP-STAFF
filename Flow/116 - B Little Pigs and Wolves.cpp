#include <bits/stdc++.h>
using namespace std;
int n, m;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
vector<vector<int>> g;
int s, t, flow;

void BFS(vector<int> &parent){
    queue<int> q;
    q.push(s);
    vector<bool> vis(n * m + 2, false);
    vis[s] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i = 0; i < n * m + 2; i++){
            if(!vis[i] and g[node][i] == 1){
                vis[i] = true;
                q.push(i);
                parent[i] = node;
            }
        }
    }
}

void Edmond_Karp(){
    while(true){
        vector<int> parent(n * m + 2, -1);
        BFS(parent);
        if(parent[t] == -1)break;
        int tt = t;
        while(true){
            int u = parent[tt];
            g[u][tt]--;
            g[tt][u]++;
            tt = u;
            if(tt == s)break;
        }
        flow++;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    g.resize(n * m + 2, vector<int> (n * m + 2, 0));
    s = n * m, t = s + 1;
    vector<vector<char>> grid(n, vector<char> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'P'){
                g[i * m + j][t] = 1;
            }else if(grid[i][j] == 'W'){
                g[s][i * m + j] = 1;
                for(int k = 0; k < 4; k++){
                    int nx = i + dx[k], ny = j + dy[k];
                    if(nx < 0 or nx >= n or ny < 0 or ny >= m or grid[nx][ny] != 'P')continue;
                        g[i * m + j][nx * m + ny] = 1;
                }
            }
        }
    }
    flow = 0;
    Edmond_Karp();
    cout << flow << '\n';
    return 0;
}
