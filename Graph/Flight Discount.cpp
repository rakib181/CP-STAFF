#include<bits/stdc++.h>
using namespace std;

class Graph{
public :
    int V;
    list<pair<long long, long long>> *l;
    int *path;
    bool inc;
    Graph(int n){
        this -> V = n;
        this -> l = new list<pair<long long, long long>> [V];
        this -> path = new int[V + 1]{-1};
        this -> inc = false;
    }

    void addEgde(int u, int v,int w){
        l[u].emplace_back(v, w);
        //l[v].emplace_back(u, w);
    }

    long long dijkstra(int src, int dest, pair<int, int> &p){
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
                long long ow = cur_dist + x.second;
                if(ow < dist[x.first]){
                    if(p.first != 0 and p.second != 0 and p.first == node and p.second == x.first){
                        inc = true;
                    }
                    if(s.find({dist[x.first], x.first}) != s.end()){
                        s.erase({dist[x.first], x.first});
                    }
                    dist[x.first] = ow;
                    path[x.first] = node;
                    s.insert({dist[x.first], x.first});
                }
            }
        }
        return dist[dest];
    }

    long long print_Path(int t, long long discount){
        vector<int> ans;
        while(t != -1) {
            ans.push_back(t);
            if(path[t] != -1) {
                for (auto x: l[path[t]]) {
                    if (x.first == t) {
                        discount = max<long long> (discount, x.second);
                    }
                }
            }
            t = path[t];
        }
        /*reverse(ans.begin(), ans.end());
        for(auto x : ans){
            cout << x << ' ';
        }*/
        return discount;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, mx = INT_MIN;
    cin >> n >> m; pair<int, int> p1 = {0, 0};
    Graph g(n + 1), g1(n + 1);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        if(w > mx) p1 = {u, v}, mx = w;
        g.addEgde(u, v, w);
        g1.addEgde(u, v, w);
    }
    pair<int, int> p2 = {0, 0};
    long long ans = g.dijkstra(1, n, p2);
    long long dis = g.print_Path(n, LONG_LONG_MIN);
    long long ok1 = ans - dis + (dis / 2);
    bool flag = false;
    for(int i = 1; i <= n; i++){
        for(auto &x : g1.l[i]){
            if(x.second == mx){
                p1 = {i, (int) x.first};
                x.second /= 2;
                flag = true;
                break;
            }
        }
        if(flag)break;
    }
    long long ok2 = g1.dijkstra(1, n, p1);
    if(g1.inc)cout << min<long long> (ok1, ok2) << '\n';
    else cout << ok1 << '\n';
    return 0;
}
