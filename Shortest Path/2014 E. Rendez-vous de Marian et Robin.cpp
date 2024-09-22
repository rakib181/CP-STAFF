#include<bits/stdc++.h>
using namespace std;

#define long long long
const long inf = 1e15 + 7;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--) {
        int n, m, h;
        cin >> n >> m >> h;
        vector<int> horse(n + 1);
        for(int i = 1; i <= h; i++){
            int x;
            cin >> x;
            horse[x] = 1;
        }
        vector<pair<int, int>> g[n + 1];
        for(int i = 1; i <= m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        auto dijkstra = [&](int source, vector<long> &withHorse, vector<long> &withoutHorse ){
            priority_queue<pair<long, pair<int, int>>, vector<pair<long, pair<int, int>>>, greater<>> pq;
            pq.push({0, {source, horse[source]}});
            while(!pq.empty()){
                auto it = pq.top();
                int u = it.second.first;
                long dist = it.first;
                int seenHorse = it.second.second;
                pq.pop();
                if(seenHorse){
                    if(withHorse[u] <= dist)continue;
                    withHorse[u] = dist;
                }else{
                    if(withoutHorse[u] <= dist)continue;
                    withoutHorse[u] = dist;
                }
                for(auto [v, w] : g[u]){
                     if(seenHorse){
                         pq.push({dist + (w / 2), {v, 1}});
                         continue;
                     }
                     if(horse[v]){
                         pq.push({dist + w, {v, 1}});
                     }else{
                         pq.push({dist + w, {v, 0}});
                     }
                }
            }
        };
        vector<long> dsWithHorse(n + 1, inf);
        vector<long> dsWithoutHorse(n + 1, inf);
        vector<long> dnWithHorse(n + 1, inf);
        vector<long> dnWithoutHorse(n + 1, inf);
        dijkstra(1, dsWithHorse, dsWithoutHorse);
        dijkstra(n, dnWithHorse, dnWithoutHorse);
        long ans = inf;
        for(int i = 1; i <= n; i++){
            long x = min(dsWithHorse[i], dsWithoutHorse[i]);
            long y = min(dnWithHorse[i], dnWithoutHorse[i]);
            ans = min(ans, max(x, y));
        }
        if(ans == inf) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}
