#include<bits/stdc++.h>
using namespace std;

class DSU{
public:
    vector<int> P, SZ;
    void init(int n){
        P.resize(n, 0);
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
}DS[102];

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i <= 101; i++){
        DS[i].init(101);
    }
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        DS[c].UNION(u, v);
    }
    int q;
    cin >> q;
    while (q--){
        int u, v;
        cin >> u >> v;
        int cnt = 0;
        for(int i = 1; i <= 100; i++){
            if(DS[i].FIND(u) == DS[i].FIND(v)){
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
