#include <bits/stdc++.h>
using namespace std;

int n, m, k;
const int N = 1e5 + 9;
const long long INF = 1e12;
vector<pair<long long, long long>> g[N];
vector<int> vis(N, 0);


void dijkstra(int src){
    priority_queue<pair<long long, long long>> pq;
    pq.push({0, src});
    while(!pq.empty() and vis[n] < k){
        auto it = pq.top();
        long long node = it.second;
        long long cur_dist = it.first;
        pq.pop();
        vis[node]++;
        if(node == n)cout << -1 * cur_dist << ' ';
        if(vis[node] <= k){
            for(auto x : g[node]){
                pq.push({cur_dist - x.second, x.first});
            }
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        long long u, v, wt;
        cin >> u >> v >> wt;
        g[u].emplace_back(v, wt);
    }
    dijkstra(1);
    return 0;
}
