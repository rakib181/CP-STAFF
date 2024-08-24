#include<bits/stdc++.h>
using namespace std;

#define long long long

const int N = 1e5 + 9, K = 18, inf = 1e9 + 7;
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

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> ed(n - 1);
    for(int i = 0; i < n - 1; i++){
        cin >> ed[i].first >> ed[i].second;
        g[ed[i].first].emplace_back(ed[i].second);
        g[ed[i].second].emplace_back(ed[i].first);
    }
    dfs(1, 0);
    vector<int> ans(n + 1, 0);
    int q;
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        int lc = lca(u, v);
        ans[u]++;
        ans[v]++;
        ans[lc] -= 2;
    }
    function<void(int, int)> f = [&](int u, int p = 0) -> void{
        for(auto v : g[u]){
            if(v == p)continue;
            f(v, u);
            ans[u] += ans[v];
        }
    };
    f(1, 0);
    for(int i = 0; i < n - 1; i++){
       int u = ed[i].first, v = ed[i].second;
       if(u == p[v][0])swap(u, v);
       cout << ans[u] << ' ';
    }
    return 0;
}
