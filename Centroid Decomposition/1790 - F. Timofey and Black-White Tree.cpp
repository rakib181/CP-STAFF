#include<bits/stdc++.h>
using namespace std;

#define long long long int

const int N = 2e5 + 9, K = 18, inf = 1e9 + 7;
vector<int> g[N], sz(N), parent(N), cal(N), depth(N);
vector<vector<int>> p(N, vector<int> (K));


void size(int u, int par){
    sz[u] = 1;
    for(auto v : g[u]){
        if(v == par or cal[v])continue;
        size(v, u);
        sz[u] += sz[v];
    }
}

int find_centroid(int u, int par, int n){
    for(auto v : g[u]){
        if(v == par or cal[v] or sz[v] * 2 < n)continue;
        return find_centroid(v, u, n);
    }
    return u;
}

void dfs(int u, int par){
    size(u, 0);
    int centroid = find_centroid(u, 0, sz[u]);
    cal[centroid] = 1;
    parent[centroid] = par;
    for(auto v : g[centroid]){
        if(v == par or cal[v])continue;
        dfs(v, centroid);
    }
}


void f(int u, int par){
    p[u][0] = par;
    for(int i = 1; i < K; i++){
        p[u][i] = p[p[u][i - 1]][i - 1];
    }
    for(auto v : g[u]){
        if(v == par)continue;
        depth[v] = depth[u] + 1;
        f(v, u);
    }
}

int lca(int u, int v){
    int x = depth[u], y = depth[v];
    if(x < y)swap(u, v);
    for(int i = K - 1; i >= 0; i--){
        int node = p[u][i];
        if(depth[node] >= depth[v]){
            u = p[u][i];
        }
    }
    if(u == v)return u;
    for(int i = K - 1; i >= 0; i--){
        int a = p[u][i], b = p[v][i];
        if(a != b){
            u = p[u][i], v = p[v][i];
        }
    }
    return p[u][0];
}

int dist(int u, int v){
    int lc = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[lc];
}
vector<int> ans(N, inf);
void change(int u){
    ans[u] = 0;
    for(int v = parent[u]; v > 0; v = parent[v]){
        ans[v] = min(ans[v], dist(u, v));
    }
}

int get(int u){
    int val = ans[u];
    for(int v = parent[u]; v > 0; v = parent[v]){
        val = min(val, ans[v] + dist(u, v));
    }
    return val;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n, node;
        cin >> n >> node;
        vector<int> x(n);
        for (int i = 1; i <= n - 1; i++) {
            cin >> x[i];
        }
        for(int i = 0; i <= n; i++){
            g[i].clear();
            sz[i] = cal[i] = parent[i] = depth[i] = 0;
            ans[i] = inf;
            for(int j = 0; j < K; j++){
                p[i][j] = 0;
            }
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        f(node, 0);
        dfs(node, 0);
        change(node);
        int val = inf;
        for(int i = 1; i <= n - 1; i++){
            cout << min(val, get(x[i])) << ' ';
            val = min(val, get(x[i]));
            change(x[i]);
        }
        cout << '\n';
    }
    return 0;
}
