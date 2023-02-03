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


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    DS.init(n + 2);
    vector<pair<int, int>> edges(m + 1);
    for(int i = 1; i <= m; i++){
        cin >> edges[i].first >> edges[i].second;
    }
    vector<bool> vis(m + 1, false);
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        vis[x] = true;
    }
    for(int i = 1; i <= m; i++){
        if(!vis[i]){
            DS.UNION(edges[i].first, edges[i].second);
        }
    }
    vector<int> deg(n + 1, 0);
    for(int i = 1; i <= m; i++){
        if(vis[i]){
            deg[DS.FIND(edges[i].first)]++;
            deg[DS.FIND(edges[i].second)]++;
        }
    }
    int odd = 0;
    for(int i = 1; i <= n; i++){
        if(DS.FIND(i) == i)odd += (deg[i] & 1);
    }
    if(odd == 0 or odd == 2)cout << "Yes" << '\n';
    else cout << "No" << '\n';
    return 0;
}
