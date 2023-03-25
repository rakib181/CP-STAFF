#include<bits/stdc++.h>
using namespace  std;
#define int long long int
const int N = 1e5 + 9;
vector<int> g[N], rev[N], order;
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
    for(auto x : rev[cur]){
        if(!vis[x]){
            dfs1(x);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, cs = 1;
    while (cin >> n >> m and (n and m)){
        for(int i = 0; i < m; i++){
            int u, v, t;
            cin >> u >> v >> t;
            if(t == 1){
                g[u].push_back(v);
                rev[v].push_back(u);
            }else{
               g[u].push_back(v);
               g[v].push_back(u);
               rev[u].push_back(v);
               rev[v].push_back(u);
            }
        }
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                dfs(i);
            }
        }
        reverse(order.begin(), order.end());
        vis.assign(n + 1, false); int cc = 0;
        for(auto x : order){
            if(!vis[x]){
                cc += 1;
                dfs1(x);
            }
        }
        if(cc == 1)cout << "1" << '\n';
        else cout << "0" << '\n';
        for(int i = 0; i < N; i++){
            g[i].clear();
            rev[i].clear();
            vis[i] = false;
        }
        order.clear();
    }
    return 0;
}
