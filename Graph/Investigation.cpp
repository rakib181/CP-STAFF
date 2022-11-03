#include<bits/stdc++.h>
using namespace std;

#define int long long int

const int mod = 1e9 + 7;

struct yo{
    int a, b, c, d;
};

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

    yo dijkstra(int src, int dest){
        vector<long long> dist(V + 1, LONG_LONG_MAX), nf(V + 1, 0), min_f(V + 1, 0), max_f(V + 1, 0);
        set<pair<long long, long long>> s;
        dist[src] = 0;
        nf[src] = 1;
        s.insert({0, src});
        while(!s.empty()){
            auto it = s.begin();
            long long node = it -> second;
            long long cur_dist = it -> first;
            s.erase(it);
            if(cur_dist > dist[node])continue;

            for(auto x : l[node]){
                if(cur_dist + x.second == dist[x.first]){
                    nf[x.first] += nf[node];
                    nf[x.first] %= mod;
                    min_f[x.first] = min(min_f[x.first], min_f[node] + 1);
                    max_f[x.first] = max(max_f[x.first], max_f[node] + 1);
                }
                if(cur_dist + x.second < dist[x.first]){
                    if(s.find({dist[x.first], x.first}) != s.end()){
                        s.erase({dist[x.first], x.first});
                    }
                    dist[x.first] = cur_dist + x.second;
                    nf[x.first] = nf[node];
                    min_f[x.first] = min_f[node] + 1;
                    max_f[x.first] = max_f[node] + 1;
                    s.insert({dist[x.first], x.first});
                }
            }
        }
        yo ans{};
        ans.a = dist[dest], ans.b = nf[dest], ans.c = min_f[dest], ans.d = max_f[dest];
        return ans;
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

    yo ans = g.dijkstra(1, n);
    cout << ans.a << ' ' << ans.b << ' ' << ans.c << ' ' << ans.d << '\n';
    return 0;
}
