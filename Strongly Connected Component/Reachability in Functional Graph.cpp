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
    int n;
    cin >> n;
    vector<int> g[n + 1], rev_g[n + 1];
    for(int u = 1; u <= n; u++){
        int v;
        cin >> v;
        g[u].emplace_back(v);
        rev_g[v].emplace_back(u);
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
    vector<int> out(cnt + 1, 0);
    vector<int> condense[n + 1], r_c[n + 1];
    for (int u = 1; u <= n; u++) {
        for (auto v: g[u]) {
            if (comp[u] != comp[v]) {
                condense[comp[u]].emplace_back(comp[v]);
                r_c[comp[v]].emplace_back(comp[u]);
                out[comp[u]] += 1;
            }
        }
    }
    vector<int> count(cnt + 1, 0);
    for(int i = 1; i <= n; i++){
        count[comp[i]] += 1;
    }
    queue<int> q;
    for(int i = 1; i <= cnt; i++){
        if(out[i] == 0){
            q.emplace(i);
        }
    }
    vector<ll> dp(cnt + 1, 0);
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        dp[u] = count[u];
        for(auto v : condense[u]){
            dp[u] += dp[v];
        }
        for(auto v : r_c[u]){
            if(--out[v] == 0){
                q.emplace(v);
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= cnt; i++){
        ans += 1LL * count[i] * (count[i] - 1);
        ans += dp[i];
    }
    cout << ans;
    return 0;
}
