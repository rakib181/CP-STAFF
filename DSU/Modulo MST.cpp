#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class DSU{
public:
    vector<int> P, SZ;
    void init(int n){
        P.assign(n, 0);
        SZ.assign(n, 1);
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

struct edge{
    int u, v;
    ll w;
};
int n, m;
ll k;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    vector<edge> g;
    for(int i = 1; i <= m; i++){
        int u, v; ll w;
        cin >> u >> v >> w;
        g.emplace_back(u, v, w);
    }
    ll ans = k;
    vector<int> p(m, 0);
    for(int i = 0; i < n - 1; i++){
        p[i] = 1;
    }
    sort(p.begin(), p.end());
    do{
      ll cost = 0;
      DS.init(n + 2);
      bool possible = true;
      for(int i = 0; i < m; i++){
          if(p[i]){
              auto [u, v, w] = g[i];
              if(DS.FIND(u) != DS.FIND(v)){
                  cost += w;
                  cost %= k;
                  DS.UNION(u, v);
              }else{
                  possible = false;
                  break;
              }
          }
      }
      if(possible){
          ans = min(ans, cost);
      }
    }while(next_permutation(p.begin(), p.end()));
    cout << ans << '\n';
    return 0;
}
