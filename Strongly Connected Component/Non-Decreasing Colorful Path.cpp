#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
vector<bool> vis(N);
vector<int> comp(N), top;

void dfs(int u, vector<int> *g){
    vis[u] = true;
    for(auto v : g[u]){
        if(!vis[v]){
            dfs(v, g);
        }
    }
    top.emplace_back(u);
}


void dfs2(int u,int c, vector<int> *g){
    comp[u] = c;
    for(auto v : g[u]){
        if(!comp[v]){
            dfs2(v, c, g);
        }
    }
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> g[n + 1], rev_g[n + 1];
    int a[n + 1];
    for(int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if(a[u] > a[v])swap(u, v);
        if(a[u] == a[v]){
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }else {
            g[u].emplace_back(v);
        }
    }
    for(int i = 1; i <= n; i++){
        for(auto v : g[i]){
            rev_g[v].emplace_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, g);
        }
    }
    reverse(top.begin(), top.end());
    int cnt = 0;
    for (auto v: top) {
        if (!comp[v]) {
            dfs2(v, ++cnt, rev_g);
        }
    }
    vector<int> condense[n + 1];
    for (int u = 1; u <= n; u++) {
        for (auto v: g[u]) {
            if (comp[u] != comp[v]) {
                condense[comp[u]].emplace_back(comp[v]);
            }
        }
    }
    const int inf = 1e9 + 7;
    vector<int> dp(n + 1, -inf);
    dp[comp[1]] = 1;
    for(int i = 1; i <= n; i++){
        if(dp[i] == -inf)continue;
        for(auto v : condense[i]){
            dp[v] = max(dp[v], dp[i] + 1);
        }
    }
    cout << (dp[comp[n]] == -inf ? 0 : dp[comp[n]]) << '\n';
    return 0;
}
