#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
vector<int> g[N], in(N), low(N);
vector<bool> vis(N); int timer;
vector<vector<bool>> road(N, vector<bool> (N));

void dfs(int cur, int par){
    vis[cur] = true;
    in[cur] = low[cur] = timer++;
    for(auto x : g[cur]){
        if(x == par)continue;
        if(!vis[x]){
            dfs(x, cur);
            low[cur] = min(low[cur], low[x]);
            if(low[x] > in[cur]){
                road[x][cur] = road[cur][x] = true;
            }else if(!road[x][cur])road[cur][x] = true;
        }else{
            low[cur] = min(low[cur], in[x]);
            if(!road[x][cur])road[cur][x] = true;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, cs = 1;
    while (cin >> n >> m){
        if(cs > 1)cout << "#" << '\n';
        if(!n and !m)break;
        timer = 1;
        for(int i = 0; i <= n; i++){
            g[i].clear();
            in[i] = 0, low[i] = 0;
            vis[i] = false;
        }
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                road[i][j] = false;
            }
        }
        for(int i = 0; i < m; i++){
                int u, v;
                cin >> u >> v;
                g[u].push_back(v);
                g[v].push_back(u);
        }
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                dfs(i, -1);
            }
        }
        cout << cs++ << "\n\n";
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(road[i][j]){
                    cout << i << ' ' << j << '\n';
                }
            }
        }
    }
    return 0;
}
