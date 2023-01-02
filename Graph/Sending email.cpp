#include<bits/stdc++.h>
using namespace std;
#define int long long int

class Graph{
public :
    int V;
    list<pair<int, int>> *l;
    Graph(int n){
        this -> V = n;
        this -> l = new list<pair<int, int>> [V];
    }

    void addEgde(int u, int v, int w){
        l[u].emplace_back(v, w);
        l[v].emplace_back(u, w);
    }

    int dijkstra(int src, int dest){
        vector<int> dist(V + 1, LONG_LONG_MAX);
        set<pair<int, int>> s;
        dist[src] = 0;
        s.insert({0, src});

        while(!s.empty()){
            auto it = s.begin();
            int node = it -> second;
            int cur_dist = it -> first;
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
        return dist[dest];
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--) {
        cout << "Case #" << cs++ << ": ";
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        Graph g(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            g.addEgde(u, v, w);
        }
        int ans = g.dijkstra(s, t);
        if (ans != LONG_LONG_MAX)cout << ans << '\n';
        else cout << "unreachable" << '\n';
    }
    return 0;
}
