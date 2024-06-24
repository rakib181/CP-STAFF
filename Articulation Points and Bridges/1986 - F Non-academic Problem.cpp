#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
vector<int> g[N];
int n, m, T, dis[N], low[N], sz[N];
ll cnt;

void dfs(int u, int p){
    dis[u] = low[u] = ++T;
    sz[u] = 1;
    for(auto v : g[u]){
        if(!dis[v]){
            dfs(v, u);
            sz[u] += sz[v];
            low[u] = min(low[u], low[v]);
            if(dis[u] < low[v]){
                cnt = max(cnt, 1LL * (n - sz[v]) * sz[v]);
            }
        }else if(v != p){
            low[u] = min(low[u], dis[v]);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m; T = 0, cnt = 0;
        for(int i = 1; i <= n; i++){
            g[i].clear();
            dis[i] = low[i] = sz[i] = 0;
        }
        for(int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        dfs(1, 0);
        cout << 1LL * n * (n - 1) / 2 - cnt << '\n';
    }
    return 0;
}
