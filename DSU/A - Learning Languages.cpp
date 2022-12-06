#include<bits/stdc++.h>
using namespace std;

class DSU{
public:
    vector<int> P;
    void init(int n){
        P.resize(n);
        iota(P.begin(), P.end(), 0);
    }

    int FIND(int v){
        if(P[v] == v)return v;
        return P[v] = FIND(P[v]);
    }

    void UNION(int u, int v){
        u = FIND(u), v = FIND(v);
        if(u == v)return;
        P[v] = u;
    }
}DS;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, ow = 0;
    cin >> n >> m;
    DS.init(n * n + 10);
    for(int i = 0; i < n; i++){
       int nn;
       cin >> nn;
       ow += nn;
        while (nn--){
           int xx;
           cin >> xx;
           DS.UNION(i, xx + n);
       }
    }
    int cc = 0;
    for(int i = 0; i < n; i++){
        if(DS.FIND(i) == i)cc++;
    }
    if(!ow) cout << n << '\n';
    else cout << cc - 1 << '\n';
    return 0;
}
