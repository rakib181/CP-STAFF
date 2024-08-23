#include<bits/stdc++.h>
using namespace std;

#define long long long
const int N = 1e5 + 9, K = 20, inf = 1e9 + 7;
vector<int> g[N], depth(N), value(N);
vector<vector<int>> p(N, vector<int> (K));

void dfs(int u, int par){
    p[u][0] = par;
    for(int i = 1; i < K; i++){
        p[u][i] = p[p[u][i - 1]][i - 1];
    }
    for(int i = 0; i < (int) g[u].size(); i++){
        int v = g[u][i];
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

int jump(int node, int x){
    for(int i = K - 1; i >= 0; i--){
        int val = value[p[node][i]];
        if(val >= x){
            node = p[node][i];
        }
    }
    return --node;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, cs = 1;
    cin >> t;
    while(t--) {
        cout << "Case " << cs++ << ":\n";
        int n, q;
        cin >> n >> q;
        for(int i = 0; i <= n; i++){
            g[i].clear();
            depth[i] = 0;
            for(int j = 0; j < K; j++){
                p[i][j] = 0;
            }
        }
        value[1] = 1;
        for(int v = 2; v <= n; v++){
            int u;
            cin >> u >> value[v];
            u++;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        dfs(1, 0);
        while(q--){
            int u, x;
            cin >> u >> x;
            u++;
            cout << jump(u, x) << '\n';
        }
    }
    return 0;
}
