#include<bits/stdc++.h>
using namespace  std;
#define int long long int
const int N = 1e5 + 9;
vector<int> g[N], order;
vector<bool> vis(N);

void dfs(int cur){
    vis[cur] = true;
    for(auto x : g[cur]){
        if(!vis[x]){
            dfs(x);
        }
    }
    order.push_back(cur);
}

void dfs1(int cur){
    vis[cur] = true;
    for(auto x : g[cur]){
        if(!vis[x]){
            dfs1(x);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while(tt--){
        cout << "Case " << cs++ << ": ";
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
        }
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                dfs(i);
            }
        }
        reverse(order.begin(), order.end());
        vis.assign(N, false); int cc = 0;
        for(auto x : order){
            if(!vis[x]){
                cc += 1;
                dfs1(x);
            }
        }
        cout << cc << '\n';
        for(int i = 0; i < N; i++){
            g[i].clear();
            vis[i] = false;
        }
        order.clear();
    }
    return 0;
}
