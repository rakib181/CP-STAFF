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
    int n, m;
    cin >> n >> m;
    DS.init(n + 2);
    vector<pair<int, pair<int, int>>> edges;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    sort(edges.begin(), edges.end());
    int tot = 0;
    for(int i = 0; i < m; i++){
        int u = edges[i].second.first, v = edges[i].second.second, c = edges[i].first;
        if(DS.FIND(u) != DS.FIND(v)){
            tot = c;
            DS.UNION(u, v);
        }
    }
    cout << tot << '\n';
    return 0;
}
