#include<bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> flights, int src, int dst, int k) {
    vector<pair<int, int>> g[n];
    for(auto it : flights){
       g[it[0]].push_back({it[1], it[2]});
    }
    vector<int> dist(n, INT_MAX);
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});
    dist[src] = 0;
    while(!q.empty()){
      auto it = q.front();
      q.pop();
      int stops = it.first;
      int node = it.second.first;
      int cur_dist = it.second.second;

      if(stops > k)continue;

      for(auto x : g[node]){
         int cur_edge = x.first;
         int w = x.second;
         if(cur_dist + w < dist[cur_edge] and stops <= k){
            dist[cur_edge] = cur_dist + w;
            q.push({stops + 1,{cur_edge, cur_dist + w}});
         }
      }
    }
    return dist[dst] != INT_MAX ? dist[dst] : -1;
}
int main(){
   int n = 3;
   vector<vector<int>> flights = {
       {0, 1, 100}, {1, 2, 100}, {0, 2, 500}
   };
   cout << findCheapestPrice(n, flights, 0, 2, 1) << '\n';
}
