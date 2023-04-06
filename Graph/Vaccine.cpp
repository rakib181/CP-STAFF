#include<bits/stdc++.h>
using namespace std;
int n, m;
class Graph{
public :
    int V;
    list<pair<long long, long long>> *l;
    vector<bool> p;
    explicit Graph(int _n){
        this -> V = _n;
        this -> p.assign(n + 1, false);
        this -> l = new list<pair<long long, long long>> [V];;
    }

    void add_Egde(int u, int v,int w) const{
        l[u].emplace_back(v, w);
        l[v].emplace_back(u, w);
    }

    void sieve(){
        p[0] = p[1] = true;
        for(int i = 2; i <= n; i++){
            if(!p[i]){
                for(int j = 2 * i; j <= n; j += i){
                    p[j] = true;
                }
            }
        }
    }


    void dijkstra() const{
        vector<long long> dist(V + 1, LONG_LONG_MAX);
        set<pair<long long, long long>> s;
        for(int i = 1; i <= n; i++){
            if(!p[i]){
                dist[i] = 0;
                s.insert({0, i});
            }
        }
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
        for(int i = 1; i <= n; i++){
            if(dist[i] == LONG_LONG_MAX)cout << "-1" << ' ';
            else cout << dist[i] << ' ';
        }
    }

};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    Graph g(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g.add_Egde(u, v, max(u, v));
    }
    g.sieve();
    g.dijkstra();
    return 0;
}
