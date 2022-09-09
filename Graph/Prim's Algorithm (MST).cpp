#include<bits/stdc++.h>
using namespace std;

class graph{
   int V;
   vector<pair<int, int>> *l;

   public:
    graph(int n){
        V = n;
        l = new vector<pair<int, int>>[n];
    }

    void addEdge(int u, int v, int w){
        l[u].push_back({v, w});
        l[v].push_back({u, w});
    }

    int prims(){
        priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>>> pq;
        bool *vis = new bool[V]{0};

        int ans = 0;
        pq.push({0, 1});

        while (!pq.empty()){
            auto best = pq.top();
            pq.pop();
            int weight = best.first;
            int node = best.second;

           
            if(vis[node])continue;
             ans += weight;
             vis[node] = true;

            for(auto x : l[node]){
                 if(!vis[x.first]){
                    pq.push({x.second, x.first});
                 }
            }
        }
         return ans;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    graph g(n + 1);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    cout << g.prims() << '\n';
    return 0;
}
