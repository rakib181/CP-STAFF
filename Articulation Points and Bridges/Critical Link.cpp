#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
vector<int> g[N], in(N), low(N);
vector<bool> vis(N); int timer;
vector<pair<int, int>> bridges;

void dfs(int cur, int par){
    vis[cur] = true;
    in[cur] = low[cur] = timer++;
    for(auto x : g[cur]){
        if(x == par)continue;
        if(!vis[x]){
            dfs(x, cur);
            low[cur] = min(low[cur], low[x]);
            if(low[x] > in[cur]){
                if(x > cur){
                    bridges.emplace_back(cur, x);
                }else{
                    bridges.emplace_back(x, cur);
                }
            }
        }else{
            low[cur] = min(low[cur], in[x]);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    cin.ignore();
    while (tt--){
        cout << "Case " << cs++ << ":" << '\n';
        int n;
        cin >> n; timer = 1;
        bridges.clear();
        for(int i = 0; i <= n; i++){
            g[i].clear();
            in[i] = 0, low[i] = 0;
            vis[i] = false;
        }
        int u, m, v; char a, b , c;
        for(int i = 0; i < n; i++){
            cin >> u >> a >> m >> c;
            while (m--){
                cin >> v;
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, -1);
            }
        }
        sort(bridges.begin(), bridges.end());
        cout << (int) bridges.size() << " critical links" << '\n';
        for(auto x : bridges){
            cout << x.first << " - " << x.second << '\n';
        }
    }
    return 0;
}
