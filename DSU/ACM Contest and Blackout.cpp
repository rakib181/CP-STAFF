#include <bits/stdc++.h>
using namespace std;

struct DSU{
    int n;
    vector<int> P, SZ;
    void INIT(int _n){
       this -> n = _n;
       this -> P.assign(n, 0);
       this -> SZ.assign(n, 1);
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
    vector<pair<int,int>> MST(vector<pair<int, pair<int, int>>> edges, int &cost){
       vector<pair<int, int>> used_edges;
       INIT(n + 2);
         for(auto x: edges){
            int u = x.second.first, v = x.second.second, c = x.first;
                if(FIND(u) != FIND(v)){
                    UNION(u, v);
                    cost += c;
                    used_edges.push_back({u, v});
                }
        }
        return used_edges;
    }
    int SECOND_MST(vector<pair<int, pair<int, int>>> edges, int id1, int id2, int edge){
        INIT(n + 2);
        int cost = 0;
        for(auto x: edges){
            int u = x.second.first, v = x.second.second, c = x.first;
            if(id1 == u and id2 == v)continue;
                if(FIND(u) != FIND(v)){
                    UNION(u, v);
                    cost += c;
                    edge--;
                }
        }
        if(edge == 1)return cost;
        else return INT_MAX;
    }
}DS;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int n, m;
        cin >> n >> m;
        DS.INIT(n + 2);
        vector<pair<int, pair<int, int>>> edges;
        for(int i = 0; i < m; i++){
            int u, v, c;
            cin >> u >> v >> c;
            edges.push_back({c,{u, v}});
        }
        sort(edges.begin(), edges.end()); int ans = 0;
        vector<pair<int, int>> MS = DS.MST(edges, ans); int cost2 = 0, ans1 = INT_MAX;
        for(int i = 0; i < (int) MS.size(); i++){
            cost2 = DS.SECOND_MST(edges, MS[i].first, MS[i].second, n);
                ans1 = min(ans1, cost2);
        }
        cout << ans << ' ' << ans1 << '\n';
    }
}
