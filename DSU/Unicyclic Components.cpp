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

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    DS.init(n + 5);
    vector<pair<int, int>> edges(m);
    for(int i = 0; i < m; i++){
        cin >> edges[i].first >> edges[i].second;
        DS.UNION(edges[i].first, edges[i].second);
    }
    vector<int> v(n + 1, 0), e(n + 1, 0);
    for(int i = 1; i <= n; i++){
        v[DS.FIND(i)] += 1;
    }
    for(auto x : edges){
        e[DS.FIND(x.first)] += 1;
    }
    if(v == e)cout << "Yes" << '\n';
    else cout << "No" << '\n';
    return 0;
}
