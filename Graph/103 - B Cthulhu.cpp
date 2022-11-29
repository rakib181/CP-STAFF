#include <bits/stdc++.h>
using namespace std;

const int N = 105;
vector<int> g[N];
vector<bool> vis(N, false);

void dfs(int cur){
    vis[cur] = true;
    for(auto x : g[cur]){
        if(!vis[x]){
            dfs(x);
        }
    }
}

int32_t main(){
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
    int cc = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cc++;
            dfs(i);
        }
    }
    if(cc == 1 and n == m)cout << "FHTAGN!" << '\n';
    else cout << "NO" << '\n';
    return 0;
}
