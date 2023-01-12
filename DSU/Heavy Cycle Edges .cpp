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
    int n, m;
    while (cin >> n >> m){
        if(!n and !m)break;
        DS.init(n + 2);
        vector<pair<int, pair<int, int>>> edges;
        for(int i = 0; i < m; i++){
            int u, v, c;
            cin >> u >> v >> c;
            edges.push_back({c, {u, v}});
        }
        sort(edges.begin(), edges.end());
        vector<int> ans;
        for(auto x : edges){
            int u = x.second.first, v = x.second.second, c = x.first;
            if(DS.FIND(u) != DS.FIND(v)){
                DS.UNION(u, v);
            }else{
                ans.push_back(c);
            }
        }
        if(ans.empty()) cout << "forest" << '\n';
        else {
            sort(ans.begin(), ans.end());
            cout << ans[0];
            for(int i = 1; i < (int) ans.size(); i++){
                cout << " " << ans[i];
            }
            cout << '\n';
        }
    }
    return 0;
}
