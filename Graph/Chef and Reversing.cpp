#include<bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1e5 + 5, INF = INT_MAX;
vector<pair<int, int>> g[N];
vector<int> dist(N, INF);

int bfs(){
    deque<int> q;
    dist[1] = 0;
    q.push_front(1);
    while(!q.empty()){
        int node = q.front();
        q.pop_front();
        for(auto x : g[node]){
            if(dist[node] + x.second < dist[x.first]){
                dist[x.first] = dist[node] + x.second;
                if(!x.second)q.push_front(x.first);
                else q.push_back(x.first);
            }
        }
    }
   return dist[n];
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v, 0);
        g[v].emplace_back(u, 1);
    }
    int ans = bfs();
    if(ans == INF)cout << "-1" << '\n';
    else cout << ans << '\n';
    return 0;
}
