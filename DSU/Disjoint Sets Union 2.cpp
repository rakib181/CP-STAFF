#include <bits/stdc++.h>
using  namespace std;

struct F{
    int x, mn, mx, sz;
};

class DSU{
public:
    vector<F> P;
    void init(int n){
       P.resize(n);
      for(int i = 0; i < n; i++){
          P[i] = {i, i, i, 1};
      }
    }

    int FIND(int v){
        if(P[v].x == v)return v;
        return P[v].x = FIND(P[v].x);
    }

    void UNION(int u, int v){
        u = FIND(u), v = FIND(v);
        if(u == v)return;
        if(P[u].sz > P[v].sz){
            swap(u, v);
        }
        P[v].x = u;
        P[u].mn = min(P[v].mn, P[u].mn);
        P[u].mx = max(P[u].mx, P[v].mx);
        P[u].sz = P[u].sz + P[v].sz;
    }
}DS;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    DS.init(n + 5);
    for(int i = 0; i < m; i++){
        string s; int u, v;
        cin >> s;
        if(s == "union"){
            cin >> u >> v;
            DS.UNION(u, v);
        }else{
            cin >> v;
            int x = DS.FIND(v);
            cout << DS.P[x].mn << ' ' <<  DS.P[x].mx << ' ' <<  DS.P[x].sz << '\n';
        }
    }
    return 0;
}
