#include <bits/stdc++.h>
using namespace std;
#define int long long int

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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
       int n;
       cin >> n;
       DS.init(n + 5); vector<pair<int, pair<int, int>>> edges;
       for(int i = 1; i <= n; i++){
           string s;
           cin >> s;
           int m;
           cin >> m;
           for(int j = 1; j <= m; j++){
               int x, c;
               cin >> x >> c;
              if(x > i) edges.push_back({c, {i, x}});
           }
       }
        sort(edges.begin(), edges.end());
        int cost = 0;
        for(auto x : edges){
            int u = x.second.first, v = x.second.second, c = x.first;
            if(DS.FIND(u) != DS.FIND(v)){
                cost += c;
                DS.UNION(u, v);
            }
        }
        cout << cost << '\n';
        DS.P.clear(), DS.SZ.clear();
    }
    return 0;
}
