#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        vector<int> g[n + 1], rev_g[n + 1];
        top.clear();
        for(int i = 1; i <= n; i++){
            vis[i] = false;
            dp[i] = 0;
            sz[i] = 0;
            comp[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        string s;
        cin >> s;
        s = '$' + s;
        for (int i = 1; i <= n; i++) {
            int u = i, v = p[i];
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
        vector<int> condense[n + 1];
        for (int u = 1; u <= n; u++) {
            for (auto v: g[u]) {
                if (comp[u] != comp[v]) {
                    condense[comp[u]].emplace_back(comp[v]);
                }
            }
        }
        for(int i = 1; i <= n; i++){
            sz[comp[i]] += (s[i] == '0');
            vis[i] = false;
        }
        for(int i = 1; i <= n; i++){
            if(!vis[i])f(i, condense);
        }
        for(int i = 1; i <= n; i++){
            cout << dp[comp[i]] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
