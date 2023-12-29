#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9;
const ll inf = 1e18 + 9;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> g[n + 1];
        for(int i = 1; i <= m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        int s[n + 1];
        for(int i = 1; i <= n; i++){
            cin >> s[i];
        }
        vector<vector<ll>> d(N, vector<ll> (n + 1, inf));
        d[1000][0] = 0;
        priority_queue<pair<pair<ll, int>, int>, vector<pair<pair<ll, int>, int>>, greater<>> pq;
        pq.push({{0, 1000}, 1});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int u = it.second;
            int j = it.first.second;
            ll cur_weight = it.first.first;
            if(d[j][u] < cur_weight)continue;
            j = min(j, s[u]);
            for(auto [v, w] : g[u]){
                if(d[j][v] > cur_weight + w * j){
                    d[j][v] = cur_weight + w * j;
                    pq.push({{d[j][v], j}, v});
                }
            }
        }
        ll ans = inf;
        for(int i = 0; i < N; i++){
            ans = min(ans, d[i][n]);
        }
        cout << ans << '\n';
    }
    return 0;
}
