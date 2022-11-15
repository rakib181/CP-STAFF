#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int findTheCity(int n, vector<vector<int>> edges, int distanceThreshold) {
       vector<vector<int>> dist(n + 1, vector<int> (n + 1, inf));
       for(int i = 0; i < (int) edges.size(); i++){
         int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
         dist[u][v] = min(dist[u][v], wt);
         dist[v][u] = min(dist[v][u], wt);
       }
       for(int i = 0; i < n; i++){
         dist[i][i] = 0;
       } 

       for(int k = 0; k < n; k++){
         for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
               if(dist[i][j] > dist[i][k] + dist[k][j]){
                  dist[i][j] = dist[i][k] + dist[k][j];
               }
            }
         }
       }

       int ans = INT_MAX;
       map<int, int> cnt;
       for(int i = 0; i < n; i++){
         for(int j = 0; j < n; j++){
            if(dist[i][j] <= distanceThreshold){
               cnt[i]++;
            }
         }
         ans = min(ans, cnt[i]);
       }
       int ok = 0;
       for(int i = 0; i < n; i++){
         for(int j = 0; j < n; j++){
            if(ans == cnt[i]){
               ok = i;
            }
         }
       }
       return ok;
}

int main(){
   int n = 4, distanceThreshold = 4;
   vector<vector<int>> edges = {
      {0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}
   };
   cout << findTheCity(n, edges, distanceThreshold) << '\n';
}
