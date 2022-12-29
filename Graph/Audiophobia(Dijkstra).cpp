#include<bits/stdc++.h>
using namespace std;

class Graph{
public :
    int V;
    list<pair<long long, long long>> *l;
    int **dist;
    Graph(int n){
        this -> V = n;
        this -> l = new list<pair<long long, long long>> [V];
        this -> dist = new int*[V + 1];
        for(int i = 0; i <= V; i++){
            this -> dist[i] = new int[V + 1];
        }
        for(int i = 0; i <= V; i++){
            for(int j = 0; j < V; j++){
                dist[i][j] = INT_MAX;
            }
        }
    }

    void addEgde(int u, int v,int w){
        l[u].emplace_back(v, w);
        l[v].emplace_back(u, w);
    }

   void dijkstra(int src, int i){
        set<pair<long long, long long>> s;
        dist[i][src] = 0;
        s.insert({0, src});

        while(!s.empty()){
            auto it = s.begin();
            long long node = it -> second;
            long long cur_dist = it -> first;
            s.erase(it);

            for(auto x : l[node]){
                if(max(cur_dist , x.second) < dist[i][x.first]){
                    if(s.find({dist[i][x.first], x.first}) != s.end()){
                        s.erase({dist[i][x.first], x.first});
                    }

                    dist[i][x.first] = max(cur_dist , x.second);
                    s.insert({dist[i][x.first], x.first});
                }
            }
        }
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int cs = 1; bool ok = true;
    while (true) {
        int n, m, q;
        cin >> n >> m >> q;
        Graph g(n + 1);
        if(!n)break;
        for(int i = 0; i < m; i++){
            int u, v, wt;
            cin >> u >> v >> wt;
            g.addEgde(u, v, wt);
        }
        for(int i = 1; i <= n; i++){
            g.dijkstra(i, i);
        }
        if(!ok){
            cout << '\n';
        }
        ok = false;
        cout << "Case #" << cs++ << '\n';
        while (q--){
            int src, des;
            cin >> src >> des;
            if(g.dist[src][des] != INT_MAX){
                cout << g.dist[src][des] << '\n';
            }else cout << "no path" << '\n';
        }
    }
    return 0;
}
