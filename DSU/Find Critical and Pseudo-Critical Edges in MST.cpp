#include<bits/stdc++.h>
using namespace std;

class DSU{
public:
    vector<int> P, SZ;
    void init(int n){
        P.resize(n);
        SZ.resize(n, 1);
        iota(P.begin(), P.end(), 0);
    }

    int FIND(int v){
        if(P[v] == v)return v;
        return P[v] = FIND(P[v]);
    }

    void UNION(int u, int v){
        u = FIND(u), v = FIND(v);
        if(u == v)return;

        if(SZ[u] > SZ[v]){
            swap(u, v);
        }
        P[v] = u;
        SZ[u] += SZ[v];
    }
}DS;

bool cmp(vector<int> &a, vector<int> &b){
   return a[2] < b[2];
}

int MST(vector<vector<int>> &edges, int avoid){
    int ans = 0;
    for(auto x : edges){
       int id = x[3];
       if(id == avoid){
         continue;
       }
       if(DS.FIND(x[0]) != DS.FIND(x[1])){
         ans += x[2];
         DS.UNION(x[0], x[1]);
       }
    }
    return ans;
}

vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> edges){
  vector<int> critical, pseudo_critical;
  DS.init(n + 1);
  for(int i = 0; i < edges.size(); i++){
     edges[i].push_back(i);
  }
  sort(edges.begin(), edges.end(), cmp);
  int min_cost = MST(edges, -1);

  for(auto x : edges){
    DS.init(n + 1);
    int cost = MST(edges, x[3]);
    if(cost > min_cost or DS.FIND(x[0]) != DS.FIND(x[1])){
      critical.push_back(x[3]);
      continue;
    }

    DS.init(n + 1);
    DS.UNION(x[0], x[1]);
    cost = x[2];
    cost += MST(edges, x[3]);
    if(cost == min_cost){
      pseudo_critical.push_back(x[3]);
    }
  }
  sort(critical.begin(), critical.end());
  sort(pseudo_critical.begin(), pseudo_critical.end());
  vector<vector<int>> ans;
  ans.push_back(critical);
  ans.push_back(pseudo_critical);
  return ans;
}

int main(){
   int n = 5;
   vector<vector<int>> edges = {
      {0,1,1},{1,2,1},{2,3,2},{0,3,2},{0,4,3},{3,4,3},{1,4,6}
   };
   vector<vector<int>> ok = findCriticalAndPseudoCriticalEdges(n, edges);
   for(int i = 0; i < 2; i++){
      for(auto x : ok[i]){
         cout << x << ' ';
      }
      cout << '\n';
   }
}
