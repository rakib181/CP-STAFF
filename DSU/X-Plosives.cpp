#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct DSU{
    int n{};
    vector<int> P, SZ;
    void INIT(int _n){
        this -> n = _n;
        P.resize(n);
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
        if(SZ[u] < SZ[v]){
            swap(u, v);
        }
        P[u] = v;
        SZ[v] += SZ[u];
    }
}DS;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int u, v;
    while (cin >> u >> v){
        DS.INIT(2e5); int cnt = 0;
        if(DS.FIND(u) != DS.FIND(v)){
            DS.UNION(u, v);
        }else{
            cnt++;
        }
        while (cin >> u and u != -1){
            cin >> v;
            if(DS.FIND(u) != DS.FIND(v)){
                DS.UNION(u, v);
            }else{
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
