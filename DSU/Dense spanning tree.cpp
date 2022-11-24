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
    vector<pair<int, pair<int, int>>> edges;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    sort(edges.begin(), edges.end());
    int ans = INT_MAX;
    for(int i = 0, k; i < m; i = k){
        DS.init(n + 2);
        int tot = 0, num_edges = 0, last;
        for(int j = i; j < m; j++){
            if(edges[j].first == edges[i].first) k = j;
            int u = edges[j].second.first, v = edges[j].second.second;
            if(DS.FIND(u) != DS.FIND(v)){
                DS.UNION(u, v);
                tot += edges[j].first;
                num_edges++;
                last = j;
            }
            if(num_edges == n - 1)break;
        }
        if(num_edges == n - 1) ans = min(ans, edges[last].first - edges[i].first);
        k++;
    }
    if(ans != INT_MAX) cout << "YES"  << '\n' << ans << '\n';
    else cout << "NO" << '\n';
    return 0;
}
