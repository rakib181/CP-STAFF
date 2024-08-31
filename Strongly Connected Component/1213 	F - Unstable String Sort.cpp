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
    int n, k;
    cin >> n >> k;
    vector<int> p(n + 1), q(n + 1);
    vector<int> g[n + 1], rev_g[n + 1]; top.clear();
    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> q[i];
    }
    for (int i = 1; i + 1 <= n; i++) {
        int u = p[i], v = p[i + 1];
        g[u].emplace_back(v);
        rev_g[v].emplace_back(u);
        u = q[i], v = q[i + 1];
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
    vector<int> condense[n + 1]; vector<int> ind(cnt + 1, 0);
    for (int u = 1; u <= n; u++) {
        for (auto v: g[u]) {
            if (comp[u] != comp[v]) {
                condense[comp[u]].emplace_back(comp[v]);
                ind[comp[v]]++;
            }
        }
    }
    if(cnt < k){
        cout << "NO\n";
        return 0;
    }
    int lst = 0; k--;
    queue<int> Q;
    for(int i = 1; i <= cnt; i++){
        if(ind[i] == 0){
            Q.emplace(i);
        }
    }
    vector<int> used(cnt + 1, -1);
    while(!Q.empty()){
        auto u = Q.front();
        Q.pop();
        used[u] = min(k, lst++);
        lst = min(lst, k);
        for(auto v : condense[u]){
            if(--ind[v] == 0){
                Q.emplace(v);
            }
        }
    }
    vector<int> ans(n + 1);
    for(int i = 1; i <= n; i++){
        ans[i] = used[comp[i]];
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i++){
        cout << char(ans[i] + 'a');
    }
    return 0;
}
