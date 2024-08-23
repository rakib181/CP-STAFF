#include<bits/stdc++.h>
using namespace std;

#define long long long
const int N = 1e5 + 9, K = 18, inf = 1e9 + 7;
vector<int> g[N], depth(N);
vector<vector<int>> p(N, vector<int> (K));
vector<vector<int>> max_flow(N, vector<int> (K, 0)), min_flow(N, vector<int> (K, 0));
vector<int> cost[N];

void dfs(int u, int c, int par){
    p[u][0] = par;
    max_flow[u][0] = c;
    min_flow[u][0] = c;
    for(int i = 1; i < K; i++){
        p[u][i] = p[p[u][i - 1]][i - 1];
        max_flow[u][i] = max(max_flow[u][i - 1], max_flow[p[u][i - 1]][i - 1]);
        min_flow[u][i] = min(min_flow[u][i - 1], min_flow[p[u][i - 1]][i - 1]);
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

pair<int, int> jump(int a, int d){
    pair<int, int> ans = {inf, -inf};
    for(int i = K - 1; i >= 0; i--){
        if((d >> i & 1)){
            ans.first = min(ans.first, min_flow[a][i]);
            ans.second = max(ans.second, max_flow[a][i]);
            a = p[a][i];
        }
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, cs = 1;
    cin >> t;
    while(t--) {
        cout << "Case " << cs++ << ":\n";
        int n;
        cin >> n;
        for (int i = 0; i <= n; i++) {
            g[i].clear();
            cost[i].clear();
            depth[i] = 0;
            for (int j = 0; j < K; j++) {
                max_flow[i][j] = 0;
                min_flow[i][j] = inf;
                p[i][j] = 0;
            }
        }
        for(int i = 1; i < n; i++){
            int u, v, w;
            cin >> u >> v >> w;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
            cost[u].emplace_back(w);
            cost[v].emplace_back(w);
        }
        dfs(1, 0, 0);
        int q;
        cin >> q;
        while (q--) {
            int a, b;
            cin >> a >> b;
            int lc = lca(a, b);
            pair<int, int> x = jump(a, (depth[a] - depth[lc])), y = jump(b, depth[b] - depth[lc]);
            cout << min(x.first, y.first) << ' ' << max(x.second, y.second) << '\n';
        }
    }
    return 0;
}
