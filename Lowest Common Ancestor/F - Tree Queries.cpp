#include<bits/stdc++.h>
using namespace std;

#define long long long
const int N = 3e5 + 9, K = 20, inf = 1e9 + 7;
vector<int> g[N], depth(N), parent(N);
vector<vector<int>> p(N, vector<int> (K));
void dfs(int u, int par){
    parent[u] = par;
    p[u][0] = par;
    for(int i = 1; i < K; i++){
        p[u][i] = p[p[u][i - 1]][i - 1];
    }
    for(auto v : g[u]){
        if(v == par)continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int lca(int a, int b){
    if(a == 1 or b == 1)return 1;
    int x = depth[a], y = depth[b];
    if(x < y)swap(a, b);
    for(int i = K - 1; i >= 0; i--){
        int v = p[a][i];
        if(depth[v] >= depth[b]){
            a = v;
        }
    }
    if(a == b)return a;
    for(int i = K - 1; i >= 0; i--){
        int u = p[a][i], v = p[b][i];
        if(u != v){
            a = u, b = v;
        }
    }
    return p[a][0];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1, 0);
    while(q--){
        int k;
        cin >> k;
        vector<int> v(k);
        for(int i = 0; i < k; i++){
            cin >> v[i];
            if(v[i] != 1) v[i] = parent[v[i]];
        }
        int node = v[0];
        for(int i = 0; i < k; i++){
            if(depth[v[i]] > depth[node]){
                node = v[i];
            }
        }
        bool possible = true;
        for(int i = 0; i < k; i++){
            int lc = lca(v[i], node);
            possible &= (lc == v[i] or lc == node);
        }
        cout << (possible ? "YES\n" : "NO\n");
    }
    return 0;
}
