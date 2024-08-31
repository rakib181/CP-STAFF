#include<bits/stdc++.h>
using namespace std;

#define long long long

class DSU{
public:
    vector<int> P, SZ;
    void INIT(int n){
        P.assign(n, 0);
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

        if(SZ[u] > SZ[v]){
            swap(u, v);
        }
        P[v] = u;
        SZ[u] += SZ[v];
    }
}dsu;

struct edge{
    int u, v, w;
    bool operator < (edge &other) const{
        return this -> w < other.w;
    }
};

long f(int n){
    return 1LL * n * (n - 1) / 2;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<edge> edges;
    for(int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    sort(edges.begin(), edges.end());
    dsu.INIT(n + 5);
    vector<pair<int, int>> c(m);
    for(int i = 0; i < m; i++){
        cin >> c[i].first;
        c[i].second = i;
    }
    sort(c.begin(), c.end());
    vector<long> ans(m);
    int j = 0; long cur = 0;
    for(int i = 0; i < m; i++){
        while(j < n - 1 and c[i].first >= edges[j].w){
            int u = edges[j].u, v = edges[j].v;
            cur -= f(dsu.SZ[dsu.FIND(u)]);
            cur -= f(dsu.SZ[dsu.FIND(v)]);
            dsu.UNION(u, v);
            cur += f(dsu.SZ[dsu.FIND(u)]);
            j++;
        }
        ans[c[i].second] = cur;
    }
    for(int i = 0; i < m; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
