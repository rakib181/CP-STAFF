#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int, int>> g[n + 1];
        for(int i = 1; i < n; i++){
            int u, v, w;
            cin >> u >> v >> w;
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        vector<int> dp(n + 1, 0), val(n + 1, 0);
        function<void(int, int) > dfs = [&](int u, int p){
            for(auto [v, w] : g[u]){
                if(v != p){
                    dp[v] = dp[u] + 1;
                    val[v] = (val[u] ^ w);
                    dfs(v, u);
                }
            }
        };
        dfs(1, -1);
        vector<vector<int>> cnt(2, vector<int> (2, 0));
        for(int i = 1; i <= n; i++){
            cnt[__builtin_popcount(val[i]) & 1][dp[i] & 1]  += 1;
        }
        cout << 2LL * cnt[0][0] * cnt[0][1] + 2LL * cnt[1][0] * cnt[1][1] << '\n';
    }
    return 0;
}
