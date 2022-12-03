#include <bits/stdc++.h>
using namespace std;

class DSU{
public:
    vector<int> P, SZ, DEG;
    void init(int n){
        P.resize(n);
        SZ.resize(n, 1);
        DEG.resize(n, 0);
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
        DS.DEG[u]++, DS.DEG[v]++;
    }
    vector<int> comp[n + 1];
    for(int i = 1; i <= n; i++){
       comp[DS.FIND(i)].push_back(i);
    }
    int v_cc = 0;
    for(int i = 1; i <= n; i++){
        if(DS.FIND(i) == i and DS.DEG[i] == 2){
            bool ok = true;
            for(auto x : comp[i]){
                if(DS.DEG[x] != 2){
                    ok = false;
                    break;
                }
            }
            if(ok)v_cc++;
        }
    }
    cout << v_cc << '\n';
    return 0;
}
