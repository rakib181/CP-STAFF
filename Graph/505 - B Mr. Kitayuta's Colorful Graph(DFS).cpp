#include<bits/stdc++.h>
using namespace std;

const int N = 105;
vector<pair<int, int>> g[N];
vector<bool> vis;

bool DFS(int src, int dst, int col){
    vis[src] = true;
    if(src == dst)return true;
    for(auto x : g[src]){
        if(x.second == col and !vis[x.first]){
            bool sub = DFS(x.first, dst, col);
            if(sub)return true;
        }
    }
    return false;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        g[u].emplace_back(v, c);
        g[v].emplace_back(u, c);
    }
    int q;
    cin >> q;
    while (q--){
        int u, v, res = 0;
        cin >> u >> v;
        for(int i = 1; i <= 100; i++){
            vis.clear();
            vis.resize(N, false);
            if(DFS(u, v, i))res++;
        }
        cout << res << '\n';
    }
    return 0;
}
