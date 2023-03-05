#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 1e5 + 9;
vector<int> g[N], rg[N], order, ans(N);
vector<bool> vis(N);

void dfs1(int cur){
    vis[cur] = true;
    for(auto x : g[cur]){
        if(!vis[x]){
            dfs1(x);
        }
    }
    order.push_back(cur);
}
void dfs2(int cur, vector<int> &comp){
    vis[cur] = true;
    comp.push_back(cur);
    for(auto x : rg[cur]){
        if(!vis[x]){
            dfs2(x, comp);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs1(i);
        }
    }
    reverse(order.begin(), order.end());
    for(int i = 1; i <= n; i++){
        vis[i] = false;
    }
    for(auto x : order){
        if(!vis[x]){
            vector<int> comp;
            dfs2(x, comp);
            if((int) comp.size() > 1){
                 for(auto xx : comp){
                     ans[xx] = 1;
                 }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
