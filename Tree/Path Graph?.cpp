#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
vector<int> g[N];
vector<bool> vis(N);

bool dfs(int cur, int par){
    vis[cur] = true;
    for(auto x : g[cur]){
        if(x != par and !vis[x]){
           bool sub = dfs(x, cur);
            if(sub)return true;
        }else if(x != par){
            return true;
        }
    }
    return false;
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
        g[v].push_back(u);
    }
    bool ok = dfs(1, -1);
    if(!ok){
        for(int i = 1; i <= n; i++){
            if(!vis[i]) ok = true;
        }
    }
    if(ok)cout << "No" << '\n';
    else cout << "Yes" << '\n';
    return 0;
}
