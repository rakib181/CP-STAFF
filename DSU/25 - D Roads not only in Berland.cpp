#include<bits/stdc++.h>
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
    int n;
    cin >> n;
    DS.init(n + 2);
    vector<pair<int, int>> close, build;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        if(DS.FIND(u) != DS.FIND(v)){
            DS.UNION(u, v);
        }else close.emplace_back(u, v);
    }
    int cur = 1, cc = 0;
    for(int i = 2; i <= n; i++){
        if(DS.FIND(cur) != DS.FIND(i)){
            build.emplace_back(1, i);
            DS.UNION(1, i);
            cc++;
        }
    }
       cout << cc << '\n';
       for(int i = 0; i < cc; i++){
           cout << close[i].first << ' ' << close[i].second << ' ' << build[i].first << ' ' << build[i].second << '\n';
       }
    return 0;
}
