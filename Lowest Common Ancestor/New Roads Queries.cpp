#include<bits/stdc++.h>
using namespace std;

#define long long long int

struct save{
    int u, rank_u, v, rank_v;
    save(int _u, int _rank_u, int _v, int _rank_v) : u(_u), rank_u(_rank_u), v(_v), rank_v(_rank_v) {};
};

struct dsu_rollback{
    vector<int> p, rank;
    stack<save> op;
    int components{};
     void init(int n){
        this -> components = n;
        this -> p.assign(n, 0);
        this -> rank.assign(n, 0);
        for(int i = 0; i < n; i++){
            p[i] = i;
            rank[i] = 0;
        }
    }
    int find(int u){
        if(u == p[u])return u;
        return find(p[u]);
    }
    bool unite(int u, int v){
        u = find(u), v = find(v);
        if(v == u){
            return false;
        }
        components--;
        if(rank[u] > rank[v])swap(u, v);
        op.emplace(u, rank[u], v, rank[v]);
        p[u] = v;
        if(rank[u] == rank[v]){
            rank[v]++;
        }
        return true;
    }
    void rollback(){
        if(op.empty())return;
        save x = op.top();
        op.pop();
        components++;
        p[x.u] = x.u, p[x.v] = x.v;
        rank[x.u] = x.rank_u, rank[x.v] = x.rank_v;
    }
}dsu;

const int N = 2e5 + 9, K = 18, inf = 1e9 + 7;
vector<pair<int, int>> g[N]; vector<int> depth(N, -1);
vector<vector<int>> p(N, vector<int> (K, 0));
vector<vector<int>> flow(N, vector<int> (K, 0));

void dfs(int u, int par, int dep){
     p[u][0] = par;
     depth[u] = dep;
     for(auto [v, w] : g[u]){
         if(v == par)continue;
         flow[v][0] = w;
         dfs(v, u, dep + 1);
     }
}

int lca(int a, int b){
    int x = depth[a], y = depth[b];
    if(x > y)swap(a, b);
    int ans = 0;
    for(int i = K - 1; i >= 0; i--){
       if(depth[b] - (1 << i) >= depth[a]){
           ans = max(ans, flow[b][i]);
           b = p[b][i];
       }
    }
    if(a == b)return ans;
    for(int i = K - 1; i >= 0; i--){
        int u = p[a][i], v = p[b][i];
        if(u != v){
            ans = max({ans, flow[a][i], flow[b][i]});
            a = u, b = v;
        }
    }
    if(p[a][0] != p[b][0]){
        return -1;
    }
    ans = max(ans, flow[a][0]);
    ans = max(ans, flow[b][0]);
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    dsu.init(n + 1);
    for(int i = 1; i <= m; i++){
         int u, v;
         cin >> u >> v;
         if(dsu.unite(u, v)){
             g[u].emplace_back(v, i);
             g[v].emplace_back(u, i);
         }
    }
    for(int i = 1; i <= n; i++){
        if(depth[i] == -1){
            dfs(i, i, 0);
        }
    }
    for(int i = 1; i < K; i++){
        for(int u = 1; u <= n; u++){
            p[u][i] = p[p[u][i - 1]][i - 1];
            flow[u][i] = max(flow[u][i - 1], flow[p[u][i - 1]][i - 1]);
        }
    }
    while(q--){
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
    return 0;
}
