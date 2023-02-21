#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<double> dp;

void dfs(int node, int par) {
    double total = 0;
    int cnt = (int) g[node].size(); if(node != par) cnt -= 1;
    for (auto& i : g[node]) {
        if (i != par) {
            dfs(i, node);
            total += dp[i] + 1;
        }
    }
    if (cnt == 0)
        dp[node] = 0;
    else
        dp[node] = total/cnt;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    g.resize(n+1);
    dp.resize(n+1);

    for (int i = 0; i < n-1; i++) {
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 1);
    cout << fixed << setprecision(8) << dp[1] << '\n';
    return 0;
}
