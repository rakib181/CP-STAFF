#include<bits/stdc++.h>
using namespace  std;
using ll = long long;
const int N = 2e5 + 9;
vector<int> g[N];
int n, sz[N], a[N];
ll ans[N];

void dfs(int u, int p){
    sz[u] = 1;
    for(auto v : g[u]){
        if(v != p){
            dfs(v, u);
            ans[1] += 1LL * (a[u] ^ a[v]) * sz[v];
            sz[u] += sz[v];
        }
    }
}

void cal(int u, int p){
    if(u != 1){
        ans[u] = ans[p];
        ans[u] -= 1LL * (a[u] ^ a[p]) * sz[u];
        ans[u] += 1LL * (a[u] ^ a[p]) * (n - sz[u]);
    }
    for(auto v : g[u]){
        if(v != p){
            cal(v, u);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= n - 1; i++){
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        dfs(1, 0);
        cal(1, 0);
        for(int i = 1; i <= n; i++){
            cout << ans[i] << " \n"[i == n];
        }
        for(int i = 1; i <= n; i++){
            g[i].clear();
            sz[i] = 0, ans[i] = 0;
        }
    }
    return 0;
}
