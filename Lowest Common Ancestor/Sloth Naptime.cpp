#include<bits/stdc++.h>
using namespace std;

#define long long long
const int N = 3e5 + 9, K = 20;
vector<int> g[N], depth(N);
vector<vector<int>> p(N, vector<int> (K));

void dfs(int u, int par){
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

int jump(int node, int d){
    for(int i = K - 1; i >= 0; i--){
        if((d >> i & 1)){
            d -= (1 << i);
            node = p[node][i];
        }
    }
    return node;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1, 0);
    int q;
    cin >> q;
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        int lc = lca(a, b);
        int d = depth[a] + depth[b] - 2 * depth[lc];
        if(d <= c){
            cout << b << '\n';
        }else if(depth[a] - depth[lc] >= c){
            cout << jump(a, c) << '\n';
        }else{
            c -= (depth[a] - depth[lc]);
            cout << jump(b, max(0, depth[b] - c - depth[lc])) << '\n';
        }
    }
    return 0;
}
