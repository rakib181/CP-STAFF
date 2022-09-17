#include<bits/stdc++.h>
using namespace std;

class edge{
    public :
    int u, v, cost;
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
      vector<int> dist (n + 1, INT_MAX);
      for(int i = 0; i < m; i++){
       cin >> edges[i].u >> edges[i].v >> edges[i].cost;
      }
      dist[1] = 0;
      while(true){
        bool ok = false;
              for(auto x : edges){
            if(dist[x.u] < INT_MAX){
                if(dist[x.v] > dist[x.u] + x.cost){
                    dist[x.v] = dist[x.u] + x.cost;
                    ok = true;
                }
            }
        }
        if(!ok)break;
      }
      for(int i = 1; i <= n; i++)cout << dist[i] << ' ';
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
