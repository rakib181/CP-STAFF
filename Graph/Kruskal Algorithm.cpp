#include<bits/stdc++.h>
using namespace std;

class DSU{
   int N;
   int *parent, *Rank;
public :
   DSU(int n){
    N = n;
    parent = new int[N + 2];
    Rank = new int[N + 2];
    for(int i = 1; i <= N; i++){
        parent[i] = i;
        Rank[i] = 1;
    }
   }

   int find(int v){
    if(parent[v] == v)return v;

    return parent[v] = find(parent[v]);
   }

   void m_union(int u, int v){
     u = find(u), v = find(v);
     if(u == v)return;

     if(Rank[u] > Rank[v]){
        parent[v] = u;
     }else if(Rank[v] > Rank[u]){
        parent[u] = v;
     }else{
        parent[v] = u;
        Rank[v]++;
     }
   }
};

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
      return a.second.second < b.second.second;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    DSU ds(n + 1);
    vector<pair<int, pair<int, int>>> ar(m);
    for(int i = 0;i < m; i++){
        cin >> ar[i].first >> ar[i].second.first >> ar[i].second.second;
    }
    sort(ar.begin(), ar.end(), compare);
    int ans = 0;
    for(int i = 0; i < m; i++){
        if(ds.find(ar[i].first) != ds.find(ar[i].second.first)){
           ds.m_union(ar[i].first, ar[i].second.first);
           ans += ar[i].second.second;
        }
    }
    cout << ans << '\n';
    return 0;
}
