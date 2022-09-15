#include<bits/stdc++.h>
using namespace std;

class Graph{
    public :
    int V;
    list<pair<int, int>> *l;
    Graph(int n){
        this -> V = n;
        this -> l = new list<pair<int, int>> [V];
    }

    void addEgde(int u, int v,int w){
        l[u].push_back({v, w});
        l[v].push_back({u, w});
    }

    int dijkstra(int src, int des){
        vector<int> dist(V + 1, INT_MAX);
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
       for(int i = 0; i < V; i++){
        cout << "Source i = "<< src <<" - > " << i << " Distence - > " << dist[i] << '\n';
       }
        return dist[des];
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    Graph g(n);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g.addEgde(u, v, w);
    }
    cout << g.dijkstra(0, 4) << '\n';
    return 0;
}
