#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 4e5 + 9;
vector<bool> vis(N);
vector<int> comp(N), top;
vector<int> dp(N), sz(N);

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

void f(int u, vector<int> *g){
    vis[u] = true;
    for(auto v : g[u]){
        if(!vis[v]){
            f(v, g);
        }
    }
    dp[u] = sz[u];
    for(auto v : g[u]){
        dp[u] += dp[v];
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, cs = 1;
    cin >> t;
    while(t--) {
        cout << "Case " << cs++ << ": ";
        int n;
        cin >> n;
        vector<int> g[n + 1], rev_g[n + 1]; top.clear();
        for(int i = 1; i <= n; i++){
            dp[i] = comp[i] = sz[i] = 0;
            vis[i] = false;
        }
        for (int i = 1; i <= n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
            rev_g[v].emplace_back(u);
        }
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
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
        vector<int> minimum_v(n + 1, n + 1);
        for(int i = 1; i <= n; i++){
            sz[comp[i]]++;
            minimum_v[comp[i]] = min(minimum_v[comp[i]], i);
        }
        vector<int> condense[n + 1];
        for (int u = 1; u <= n; u++) {
            for (auto v: g[u]) {
                if (comp[u] != comp[v]) {
                    condense[comp[u]].emplace_back(comp[v]);
                }
            }
        }
        for(int i = 1; i <= n; i++){
            vis[i] = false;
        }
        for(int i = 1; i <= cnt; i++){
            if(!vis[i]){
                f(i, condense);
            }
        }
        int ans = n + 1, mx = 0;
        for(int i = 1; i <= cnt; i++){
           if(dp[i] >= mx){
               ans = min(ans, minimum_v[i]);
               mx = dp[i];
           }
        }
        cout << ans << '\n';
    }
    return 0;
}
