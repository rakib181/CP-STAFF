#include<bits/stdc++.h>
using namespace std;

const int N = 105;
vector<int> gp[N];
vector<bool> vis(N, false);
vector<int> color(N, 0);
bool ok;

void dfs(int src){
    vis[src] = true;
    for(auto u : gp[src]){
        if(!vis[u]){
            color[u] = color[src] ^ 1;
            dfs(u);
        }else{
            if(color[u] == color[src]){
                ok = false;
            }
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, e;
    cin >> n >> e;
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }
    ok = true;
    for(int i = 1; i <= n; i++){
        if(!vis[i])dfs(i);
    }
    if(ok)cout << "Bipertite !" << '\n';
    else cout << "NO !" << '\n';
    return 0;
}
