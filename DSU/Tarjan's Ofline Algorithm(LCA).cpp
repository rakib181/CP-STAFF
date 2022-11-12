#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
vector<int> g[N];
vector<pair<int, int>> Q[N];
vector<int> lca(N), f(N);
vector<bool> vis(N, false);

int find(int v){
    if(f[v] == v)return v;
    return f[v] = find(f[v]);
}

void Tarjan(int cur){
    vis[cur] = true;
    for(auto x : g[cur]){
       if(!vis[x]) {
           Tarjan(x);
           f[x] = cur;
       }
    }
    for(auto xx : Q[cur]){
        if(vis[xx.first]){
            lca[xx.second] = find(xx.first);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)f[i] = i;
    for(int i = 2; i <= n; i++){
        int x;
        cin >> x;
        g[x].push_back(i);
    }
    for(int i = 1; i <= q; i++){
        int u, v;
        cin >> u >> v;
        Q[u].emplace_back(v, i);
        Q[v].emplace_back(u, i);
    }
    Tarjan(1);
    for(int i = 1; i <= q; i++){
        cout << lca[i] << '\n';
    }
    return 0;
}
