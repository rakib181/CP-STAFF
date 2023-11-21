#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 205, inf = (int) 1e9 + 7;
int n, m, k, r[N], d[N][N], res;
bool vis[N];

void dfs(int i, int last, int dist){
    if(i == k + 1){
        res = min(res, dist);
        return;
    }
    for(int x = 1; x <= k; x++){
         if(!vis[x]){
             vis[x] = true;
             if(last == 0)dfs(i + 1, x, dist);
             else dfs(i + 1, x, d[r[last]][r[x]] + dist);
             vis[x] = false;
         }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++){
        cin >> r[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            d[i][j] = inf;
        }
    }
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w);
        d[v][u] = min(d[v][u], w);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j)d[i][j] = 0;
        }
    }
    for(int u = 1; u <= n; u++){
        for(int v = 1; v <= n; v++){
            for(int w = 1; w <= n; w++){
                d[v][w] = min(d[v][w], d[v][u] + d[u][w]);
            }
        }
    }
    res = inf;
    dfs(1, 0, 0);
    cout << res << '\n';
    return 0;
}
