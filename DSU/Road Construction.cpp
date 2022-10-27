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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, sz = 1, cc;
    cin >> n >> m;
    cc = n;
    DS.init(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        if(DS.FIND(u) != DS.FIND(v)){
            cc--;
            DS.UNION(u, v);
        }
        sz = max(sz, DS.SZ[DS.FIND(u)]);
        cout << cc << ' ' << sz << '\n';
    }
    return 0;
}
