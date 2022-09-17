#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e15;

int32_t main(){
     ios_base::sync_with_stdio(0);
      cin.tie(0); 
      int n, m, q;
      cin >> n >> m >> q;
      vector<vector<long long>> dist(n + 1, vector<long long> (n + 1, INF));
      for(int i = 1; i <= n; i++){
        dist[i][i] = 0;
      }

      for(int i = 0; i < m; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        if(dist[u][v] > wt){
            dist[u][v] = wt;
            dist[v][u] = wt;
        }
      }

      for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                long long cur = dist[i][k] + dist[k][j];
                if(cur < dist[i][j]){
                    dist[i][j] = cur;
                    dist[j][i] = cur;
                }
            }
        }
      }
      while(q--){
        int src, dest;
        cin >> src >> dest;
        if(dist[src][dest] == INF)cout << "-1" << '\n';
        else cout << dist[src][dest] << '\n';
      }
      return 0;
}
