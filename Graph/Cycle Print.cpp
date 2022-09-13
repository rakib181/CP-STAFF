#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> g[N];
vector<int> vis(N, 0), parent(N, -1);
 
void dfs(int cur, int par = -1){
    vis[cur] = 1;
    for(auto x : g[cur]){
        if(!vis[x]){
            parent[x] = cur;
            dfs(x, cur);
        }else if(x != par and vis[x] == 1){
            int u = x, v = cur;
            while(v != u){
                cout << v << ' ';
                v = parent[v];
            }
            cout << v << '\n';
            exit(0);
        }
    }
    vis[cur] = 2;
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
    for(int i = 1; i <= n; i++){
        if(!vis[i])dfs(i);
    }
    return 0;
}
