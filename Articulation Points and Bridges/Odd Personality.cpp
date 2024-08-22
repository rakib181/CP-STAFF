#include<bits/stdc++.h>
using namespace std;
#define long long long

const int N = 1e4 + 9;
vector<int> g[N], d(N), en(N), vis(N);
vector<pair<int, int>> bridge;
set<int> ng[N];
int n, m, tme, cnt;

void dfs(int u, int p){
    d[u] = en[u] = ++tme;
    for(auto v : g[u]){
        if(!d[v]){
            dfs(v, u);
            en[u] = min(en[u], en[v]);
            if(d[u] < en[v]){
                bridge.emplace_back(u, v);
                ng[u].erase(v);
                ng[v].erase(u);
            }
        }else if(v != p){
            en[u] = min(en[u], d[v]);
        }
    }
}

bool cycle;
void odd_cycle(int u, int p, int len){
    vis[u] = 1;
    d[u] = len;
    cnt++;
    for(auto v : ng[u]){
        if(!vis[v]){
            odd_cycle(v, u, len + 1);
        }else if(v != p and !((d[u] - d[v]) & 1)){
            cycle = true;
        }
    }
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while(tt--) {
        cout << "Case " << cs++ << ": ";
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            g[i].clear();
            ng[i].clear();
            d[i] = en[i] = vis[i] = 0;
        }
        bridge.clear();
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            u++, v++;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
            ng[u].insert(v);
            ng[v].insert(u);
        }
        tme = 0;
        for(int i = 1; i <= n; i++){
            if(!d[i]){
                dfs(i, 0);
            }
        }
        for(int i = 1; i <= n; i++)d[i] = 0;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                cnt = 0;
                cycle = false;
                odd_cycle(i, 0, 0);
                if(cycle)ans += cnt;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
