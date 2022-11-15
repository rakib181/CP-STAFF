#include<bits/stdc++.h>
using namespace std;

#define inf  1e9

vector<int> travelByCar(int n,int l, vector<vector<int>>edges ,vector<vector<int>> queries){
    vector<vector<int>> dist (n + 1, vector<int> (n + 1, inf)); 
    vector<vector<int>> fuel(n + 1, vector<int> (n + 1, inf));
    for(int i = 0; i < (int) edges.size(); i++){
       int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
       u--, v--;
       dist[u][u] = 0;
       dist[v][v] = 0;
       dist[u][v] = wt;
       dist[v][u] = wt;
       fuel[u][u] = 0;
       fuel[v][v] = 0;
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
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
         if(i == j)continue;

         if(dist[i][j] <= l){
            fuel[i][j] = 1;
         }
      }
    }

    for(int k = 0; k < n; k++){
      for(int i = 0; i < n; i++){
         for(int j = 0; j < n; j++){
            if(fuel[i][j] > fuel[i][k] + fuel[k][j]){
               fuel[i][j] = fuel[i][k] + fuel[k][j];
            }
         }
      }
    }
    vector<int> ans;
    for(int i = 0; i < (int) queries.size(); i++){
      int u = queries[i][0], v = queries[i][1];
      u--, v--;
      if(fuel[u][v] ==inf)ans.push_back(-1);
      else ans.push_back(fuel[u][v] - 1);
    }
    return ans;
}

int main(){
   int n = 3, l = 5;
   vector<vector<int>> edges = {
       {1, 2, 3}, {2, 3, 3}
   };
   vector<vector<int>> queries = {
      {3, 2}, {1, 3}
   };

   auto ok = travelByCar(n, l, edges, queries);
   for(auto x : ok){
      cout << x << ' ';
   }
}
