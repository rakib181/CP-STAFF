#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e15, NINF = -INF;

class edge{
    public :
    long long u, v, cost;
};

int32_t main(){
     ios_base::sync_with_stdio(0);
      cin.tie(0); 
      #ifndef ONLINE_JUDGE 
      freopen("input.txt","r",stdin); 
      freopen("output.txt","w",stdout); 
      #endif
      auto start=clock();
      int n, m;
      cin >> n >> m;
      vector<edge> edges(m + 1);
      vector<long long> dist (n + 1, INF);
      for(int i = 0; i < m; i++){
       cin >> edges[i].u >> edges[i].v >> edges[i].cost;
       edges[i].cost *= -1;
      }
      dist[1] = 0;
        for(int i = 0; i < n; i++){
              for(auto x : edges){
              if(dist[x.u] == INF)continue;   
              dist[x.v] = min<long long>(dist[x.v], dist[x.u] + x.cost);
              dist[x.v] = max<long long>(dist[x.v], NINF);
        }
      }

       for(int i = 0; i < n; i++){
              for(auto x : edges){
              if(dist[x.u] == INF)continue;   
              dist[x.v] = max<long long>(dist[x.v], NINF);
              if(dist[x.v] > dist[x.u] + x.cost){
                dist[x.v] = NINF;
              }
        }
      }
      
      if(dist[n] != NINF)cout << -1 * dist[n] << '\n';
      else cout << "-1" << '\n';
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
