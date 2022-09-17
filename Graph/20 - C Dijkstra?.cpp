#include<bits/stdc++.h>
using namespace std;

class Graph{
public :
    int V;
    list<pair<long long, long long>> *l;
    int *path;
    Graph(int n){
        this -> V = n;
        this -> l = new list<pair<long long, long long>> [V];
        this -> path = new int[V + 1]{-1};
    }

    void addEgde(int u, int v,int w){
        l[u].emplace_back(v, w);
        l[v].emplace_back(u, w);
    }

    long long dijkstra(int src, int dest){
        vector<long long> dist(V + 1, LONG_LONG_MAX);
        set<pair<long long, long long>> s;
        dist[src] = 0;
        path[src] = -1;
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
                    path[x.first] = node;
                    s.insert({dist[x.first], x.first});
                }
            }
        }
       return dist[dest];
    }

    void print_Path(int t){
        vector<int> ans;
        while(t != -1) {
            ans.push_back(t);
            t = path[t];
        }
        reverse(ans.begin(), ans.end());
        for(auto x : ans){
            cout << x << ' ';
        }
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    Graph g(n + 1);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g.addEgde(u, v, w);
    }
     if(g.dijkstra(1, n) != LONG_LONG_MAX)
                g.print_Path(n);
     else cout << "-1" << '\n';
    return 0;
}
