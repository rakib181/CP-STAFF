#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int INF = 1e12;

class Graph{
public :
    int V;
    list<pair<int, int>> *l;
    explicit Graph(int n){
        this -> V = n;
        this -> l = new list<pair<int, int>> [V];
    }

    void addEgde(int u, int v,int w) const{
        l[u].emplace_back(v, w);
        l[v].emplace_back(u, w);
    }

    void dijkstra(int src, int n){
        vector<int> dist(V + 1, INF);
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
        for(int i = 1; i <= n; i++){
            if(i == src)continue;
            if(dist[i] != INF)cout << dist[i] << ' ';
            else cout << "-1" << ' ';
        }
        cout << '\n';
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        int n, m;
        cin >> n >> m;
        Graph gp(n + 2);
        for(int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            gp.addEgde(u, v, w);
        }
        int src;
        cin >> src;
        gp.dijkstra(src, n);
    }
    return 0;
}
