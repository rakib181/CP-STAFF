#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
vector<int> g[N], in(N), low(N);
vector<bool> vis(N), is_cut(N); int timer;

void is_art_point(int node){
    is_cut[node] = true;
}

void dfs(int cur, int par){
    vis[cur] = true;
    in[cur] = low[cur] = timer++;
    int child = 0;
    for(auto x : g[cur]){
        if(x == par)continue;
        if(!vis[x]){
            dfs(x, cur);
            child++;
            low[cur] = min(low[cur], low[x]);
            if(low[x] >= in[cur] and par != -1){
                is_art_point(cur);
            }
        }else{
            low[cur] = min(low[cur], in[x]);
        }
    }
    if(par == -1 and child > 1)is_art_point(cur);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--){
        int n, m; timer = 1;
        cin >> n >> m;
        for(int i = 0; i < N; i++){
            g[i].clear();
            in[i] = low[i] = -1;
            vis[i] = false;
            is_cut[i] = false;
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
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(is_cut[i])cnt++;
        }
        cout << "Case " << cs++ << ": " << cnt << '\n';
    }
    return 0;
}
