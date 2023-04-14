#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
const ll inf = 1e15;
vector<pair<int, ll>> g[N];
vector<ll> dist(N, inf);
vector<int> P(N, -1);

void PATH(int t){
    if(t == -1)return;
    PATH(P[t]);
    cout << t << ' ';
}

void dijkstra(int src, int dest){
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0, src});
    dist[src] = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.second; ll cost = it.first;
        for(auto x : g[node]){
            ll cur_w = x.second; int cur_node = x.first;
            if(cost + cur_w <= dist[cur_node]){
                dist[cur_node] = cost + cur_w;
                P[cur_node] = node;
                pq.push({dist[cur_node], cur_node});
            }
        }
    }
    int t = dest;
    if(dist[dest] == inf)cout << "-1\n";
    else PATH(t);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    dijkstra(1, n);
    return 0;
}
