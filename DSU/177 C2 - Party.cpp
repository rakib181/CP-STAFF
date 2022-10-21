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
    int n, k;
    cin >> n >> k;
    DS.init(n + 1);
    for(int i = 0; i < k; i++){
        int u, v;
        cin >> u >> v;
        DS.UNION(u, v);
    }
    int m;
    cin >> m;
    vector<pair<int, int>> q;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        q.emplace_back(x, y);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if (DS.FIND(i) == i) {
            int sz = DS.SZ[DS.FIND(i)];
            bool found = false;
            for (auto x: q) {
                if (DS.FIND(x.first) == i and DS.FIND(x.second) == i) {
                  found = true;
                  break;
                }
            }
            if(!found)ans = max(ans, sz);
        }
    }
    cout << ans << '\n';
    return 0;
}
