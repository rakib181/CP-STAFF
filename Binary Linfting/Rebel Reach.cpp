#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 9, MX = 23;
vector<int> g[N];
ll sum[N];
int n, guards[N], p[N][MX];

void dfs(int u, int par){
    if(u == par){
        p[u][0] = u;
        sum[u] = guards[u];
    }else{
        p[u][0] = par;
        sum[u] = sum[par] + guards[u];
    }
    for(int i = 1; i < MX; i++){
        p[u][i] = p[p[u][i - 1]][i - 1];
    }
    for(auto v : g[u]){
        if(v != par){
            dfs(v, u);
        }
    }
}

int query(int u, ll x){
    int node = u; ll val = x;
    for(int i = 22; i >= 0; i--){
        if(sum[u] - sum[p[u][i]] + guards[p[u][i]] <= x){
            x -= (sum[u] - sum[p[u][i]]);
            u = p[u][i];
        }
    }
    if(u == 1)return u;
    if(val - (sum[node] - sum[u] + guards[u]) > 0)u = p[u][0];
    return u;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            g[i].clear();
            sum[i] = 0;
            for(int j = 0; j < MX; j++){
                p[i][j] = 0;
            }
        }
        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        for(int i = 1; i <= n; i++){
            cin >> guards[i];
        }
        dfs(1, 1);
        int q;
        cin >> q;
        while(q--){
            int node; ll x;
            cin >> node >> x;
            cout << query(node, x) << '\n';
        }
    }
    return 0;
}
