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
}DS1, DS2;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    DS1.init(n + 2), DS2.init(n + 2);
    for(int i = 0; i < m1; i++){
        int u, v;
        cin >> u >> v;
        DS1.UNION(u, v);
    }
    for(int i = 0; i < m2; i++){
        int u, v;
        cin >> u >> v;
        DS2.UNION(u, v);
    }
    vector<pair<int, int>> ans;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(DS1.FIND(i) != DS1.FIND(j) and DS2.FIND(i) != DS2.FIND(j)){
                ans.emplace_back(i, j);
                DS1.UNION(i, j);
                DS2.UNION(i, j);
            }
        }
    }
    cout << (int) ans.size() << '\n';
    for(auto x : ans){
        cout << x.first << ' ' << x.second << '\n';
    }
    return 0;
}
