#include<bits/stdc++.h>
using namespace std;

#define long long long
const int N = 5e4 + 9, K = 18, inf = 1e9 + 7;
vector<int> g[N], depth(N);
vector<vector<int>> p(N, vector<int> (K));
vector<vector<int>> flow(N, vector<int> (K, inf));
vector<int> cost[N];

void dfs(int u, int c, int par){
    p[u][0] = par;
    flow[u][0] = c;
    for(int i = 1; i < K; i++){
        p[u][i] = p[p[u][i - 1]][i - 1];
        flow[u][i] = max(flow[u][i - 1], flow[p[u][i - 1]][i - 1]);
    }
    for(int i = 0; i < (int) g[u].size(); i++){
        int v = g[u][i];
        int new_c = cost[u][i];
        if(v == par)continue;
        depth[v] = depth[u] + 1;
        dfs(v, new_c, u);
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

int jump(int a, int d){
    int ans = -inf;
    for(int i = K - 1; i >= 0; i--){
        if((d >> i & 1)){
            ans = max(ans, flow[a][i]);
            a = p[a][i];
        }
    }
    return ans;
}

class DSU{
public:
    vector<int> P, SZ;
    void INIT(int n){
        P.assign(n, 0);
        SZ.assign(n, 1);
        iota(P.begin(), P.end(), 0);
    }

    int FIND(int v){
        if(P[v] == v)return v;
        return P[v] = FIND(P[v]);
    }

    void UNION(int u, int v){
        u = FIND(u), v = FIND(v);
        if(u == v)return;

        if(SZ[u] > SZ[v]){
            swap(u, v);
        }
        P[v] = u;
        SZ[u] += SZ[v];
    }
}dsu;

struct edge{
    int u, v, w;
    bool operator < (edge &other) const{
        return this -> w < other.w;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, cs = 1;
    cin >> t;
    while(t--) {
        cout << "Case " << cs++ << ":\n";
        int n, m;
        cin >> n >> m;
        for (int i = 0; i <= n; i++) {
            g[i].clear();
            cost[i].clear();
            depth[i] = 0;
            for (int j = 0; j < K; j++) {
                flow[i][j] = p[i][j] = 0;
            }
        }
        vector<edge> ed(m);
        for (int i = 0; i < m; i++) {
            cin >> ed[i].u >> ed[i].v >> ed[i].w;
        }
        sort(ed.begin(), ed.end());
        dsu.INIT(n + 5);
        for (auto e: ed) {
            int u = e.u, v = e.v, w = e.w;
            if (dsu.FIND(u) != dsu.FIND(v)) {
                g[u].emplace_back(v);
                g[v].emplace_back(u);
                cost[u].emplace_back(w);
                cost[v].emplace_back(w);
                dsu.UNION(u, v);
            }
        }
        dfs(1, 0, 0);
        int q;
        cin >> q;
        while (q--) {
            int a, b;
            cin >> a >> b;
            int lc = lca(a, b);
            cout << max(jump(a, (depth[a] - depth[lc])), jump(b, depth[b] - depth[lc])) << '\n';
        }
    }
    return 0;
}
