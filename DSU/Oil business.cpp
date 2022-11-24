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
    int n, m; long long s;
    cin >> n >> m >> s;
    DS.init(n + 2);
    vector<pair<int, pair<int, pair<int, pair<int, int>>>>> edges;
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back({c, {u, {v, {0, i + 1}}}});
    }
    sort(edges.rbegin(), edges.rend());
    vector<int> ans;
    for(int i = 0; i < m; i++){
        int u = edges[i].second.first , v = edges[i].second.second.first;
        if(DS.FIND(u) == DS.FIND(v))continue;
        DS.UNION(u, v);
        edges[i].second.second.second.first = 1;
    }
    for(int i = m - 1; i >= 0; i--){
        if(!edges[i].second.second.second.first){
            if (s >= edges[i].first){
                s -= edges[i].first;
                ans.push_back(edges[i].second.second.second.second);
            }
        }
    }
    cout << (int) ans.size() << '\n';
    for(auto x : ans){
        cout << x << ' ';
    }
    return 0;
}
