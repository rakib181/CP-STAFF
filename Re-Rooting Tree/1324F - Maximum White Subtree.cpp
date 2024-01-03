#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int n, a[N];
vector<int> g[N];
int dp[N], ans[N];

void dfs(int u, int p){
    dp[u] = a[u];
    for(auto v : g[u]){
        if(v != p){
            dfs(v, u);
            dp[u] += max(0, dp[v]);
        }
    }
}

void cal(int u, int p){
    if(p){
        ans[u] = dp[u];
        int val = ans[p] - max(0, dp[u]);
        ans[u] += max(0, val);
    }
    for(auto v : g[u]){
      if(v != p) {
          cal(v, u);
      }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == 0) a[i] = -1;
    }
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1, 0);
    ans[1] = dp[1];
    cal(1, 0);
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " \n"[i == n];
    }
    return 0;
}
