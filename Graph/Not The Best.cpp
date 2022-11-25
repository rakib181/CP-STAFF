#include<bits/stdc++.h>
using namespace std;

class Graph{
public :
    int V;
    list<pair<long long, long long>> *l;
    Graph(int n){
        this -> V = n;
        this -> l = new list<pair<long long, long long>> [V];
    }

    void addEgde(int u, int v,int w){
        l[u].emplace_back(v, w);
        l[v].emplace_back(u, w);
    }

    vector<long long> dijkstra(int src){
        vector<long long> dist(V + 1, LONG_LONG_MAX);
        set<pair<long long, long long>> s;
        dist[src] = 0;
        s.insert({0, src});

        while(!s.empty()){
            auto it = s.begin();
            long long node = it -> second;
            long long cur_dist = it -> first;
            s.erase(it);

            for(auto x : l[node]){
                if(cur_dist + x.second < dist[x.first]){
                    if(s.find({dist[x.first], x.first}) != s.end()){
                        s.erase({dist[x.first], x.first});
                    }

                    dist[x.first] = cur_dist + x.second;
                    s.insert({dist[x.first], x.first});
                }
            }
        }
        return dist;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, idx = 1;
    cin >> tt;
    while (tt--) {
        cout << "Case " << idx++ << ": ";
        int n, m;
        cin >> n >> m;
        Graph g(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            g.addEgde(u, v, w);
        }
        vector<long long> dist2 = g.dijkstra(1);
        vector<long long> dist = g.dijkstra(n);
        long long ans = LONG_LONG_MAX;
        for (int i = 1; i <= n; i++) {
            for (auto x: g.l[i]) {
                long long d = dist2[i] + dist[x.first] + x.second;
                if (d > dist2[n]) {
                    ans = min<long long>(ans, d);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
