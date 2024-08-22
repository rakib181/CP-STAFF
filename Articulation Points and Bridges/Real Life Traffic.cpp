#include<bits/stdc++.h>
using namespace std;
#define long long long

const int N = 1e4 + 9;
vector<int> g[N], d(N), en(N), scc(N);
vector<pair<int, int>> bridge;
set<int> ng[N];
int n, m, tme;

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


void dfs_scc(int u, int c){
    scc[u] = c;
    for(auto v : ng[u]){
        if(scc[v] == -1){
            dfs_scc(v, c);
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
            d[i] = en[i] = 0;
            scc[i] = -1;
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
        tme = 0; int sc = 1;
        for(int i = 1; i <= n; i++){
            if(!d[i]){
                dfs(i, 0);
            }
        }
        for(int i = 1; i <= n; i++){
            if(scc[i] == -1){
                dfs_scc(i, sc);
                sc++;
            }
        }
        vector<int> count(sc + 1, 0);
        for(auto [x, y] : bridge){
            count[scc[x]]++;
            count[scc[y]]++;
        }
        int cnt = 0;
        for(int i = 1; i < sc; i++){
            cnt += (count[i] == 1);
        }
        cout << (cnt + 1) / 2 << '\n';
    }
    return 0;
}
