#include <bits/stdc++.h>
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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    DS.init(n + 2);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        DS.UNION(u, v);
    }
    int cc = DS.FIND(1); bool ok = true;
    for(int i = 2; i <= n; i++){
        if(DS.FIND(i) != cc){
            ok = false;
            break;
        }
    }
    if(ok and n == m)cout << "FHTAGN!" << '\n';
    else cout << "NO" << '\n';
    return 0;
}
