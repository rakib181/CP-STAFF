#include<bits/stdc++.h>
using namespace std;
#define int long long int

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
    }
    void dijkstra(int src, int t, int n){
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
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] <= t)cnt++;
        }
      cout << cnt << '\n';
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, src, t, m;
    cin >> n >> src >> t >> m;
    Graph g(n + 1);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g.addEgde(v, u, w);
    }
    g.dijkstra(src, t, n);
    return 0;
}
