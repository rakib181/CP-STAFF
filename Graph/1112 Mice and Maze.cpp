#include<bits/stdc++.h>
using namespace std;

const int N = 105, INF = 1e9 + 7;
vector<pair<int, int>> g[N];
vector<int> dist(N, INF);

void dijkstra(int src){
    set<pair<int, int>> s;
    dist[src] = 0;
    s.insert({0, src}); 
    while(!s.empty()){
        auto it = s.begin();
        int node = it -> second;
        int cur_dist = it -> first;
        s.erase(it);

        for(auto x : g[node]){
            int ow = cur_dist + x.second;
            if(ow < dist[x.first]){
               if(s.find({dist[x.first], x.first}) != s.end()){
                s.erase({dist[x.first], x.first});
               }
               dist[x.first] = cur_dist + x.second;
               s.insert({dist[x.first], x.first});
            }
        }
    }
}

int32_t main(){
     ios_base::sync_with_stdio(0);
      cin.tie(0); 
      #ifndef ONLINE_JUDGE 
      freopen("input.txt","r",stdin); 
      freopen("output.txt","w",stdout); 
      #endif
      auto start=clock();
      int tt;
      cin >> tt;
      for(int cs = 1; cs <= tt; cs++){
        int n, ex, t, m, cnt = 0;
        cin >> n >> ex >> t >> m;
        for(int i = 1; i <= n; i++){
            g[i].clear();
            dist[i] = INF;
        }
        for(int i = 0; i < m; i++){
            int u, v, wt;
            cin >> u >> v >> wt;
            g[v].push_back({u, wt});
        }
        dijkstra(ex);
        for(int i = 1; i <= n; i++){
            if(dist[i] <= t)cnt++;
        }
        if(cs > 1)cout << '\n';
        cout << cnt << '\n';
      }
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
