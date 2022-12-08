#include<bits/stdc++.h>
using namespace std;
#define int long long int

class Dials{
    int V, inf = 1e10;
    list<pair<int , int>> *g;
public:
    void init(int _n){
        this -> V = _n;
        this -> g = new list<pair<int, int>> [V];
    }

    void add_edge(int u, int v, int wt) const{
        g[u].emplace_back(v, wt);
        g[v].emplace_back(u, wt);
    }
    void shortest_path(int src, int W){
        vector<pair<int , list<int> :: iterator>> dist(V);
        for(int i = 0; i < V; i++){
            dist[i].first = inf;
        }
        list<int> B[W * V + 1];
        B[0].push_back(src);
        dist[src].first = 0;

        int idx = 0;
        while (true){
            while (B[idx].empty() and idx < W * V){
                idx++;
            }
            if(idx == W * V)break;

            int u = B[idx].front();
            B[idx].pop_front();
            for(auto x : g[u]){
                int v = x.first;
                int wt = x.second;

                int du = dist[u].first;
                int dv = dist[v].first;

                if(dv > du + wt){
                    if(dv != inf){
                        B[dv].erase(dist[v].second);
                    }

                    dist[v].first = du + wt;
                    dv = dist[v].first;
                    B[dv].push_front(v);

                    dist[v].second = B[dv].begin();
                }
            }
        }
        for(int i = 0; i < V; i++){
            cout << dist[i].first << ' ';
        }
    }


}GP;


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, W = 0;
    cin >> n >> m;
    GP.init(n);
    for(int i = 0; i < m; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        GP.add_edge(u, v, wt);
        W = max(W, wt);
    }
    GP.shortest_path(0, W);
    return 0;
}
