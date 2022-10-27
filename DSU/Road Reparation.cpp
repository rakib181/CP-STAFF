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
    int n, m, tot = 0, cc = 0;
    cin >> n >> m;
    DS.init(n + 1);
    vector<pair<int, pair<int, int>>> e;
    for(int i = 0; i < m; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        e.push_back({wt, {u, v}});
    }
    sort(e.begin(), e.end());
    for(auto x : e){
        if(DS.FIND(x.second.first) != DS.FIND(x.second.second)){
            tot += x.first;
            DS.UNION(x.second.first, x.second.second);
        }
    }
    for(int i = 1; i <= n; i++){
        if(DS.FIND(i) == i){
            cc++;
        }
    }
    if(cc == 1){
        cout << tot << '\n';
    }else cout << "IMPOSSIBLE" << '\n';
    return 0;
}
