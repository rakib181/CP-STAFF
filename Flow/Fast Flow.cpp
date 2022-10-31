#include <bits/stdc++.h>
using namespace std;

#define int long long int

class Dinic{
public:
    struct edge{
        int u, v, w;
    };
    vector<vector<int>> g;
    vector<edge> edges;
    vector<int> level;
    vector<int> edge_sz;
    int n, source, sink, ec = 0;
   Dinic(int n, int source, int sink){
        this -> n = n;
        this -> source = source;
        this -> sink = sink;
        g.resize(this -> n);
        level.resize(this -> n);
        edge_sz.resize(this -> n);
    }

    void add_edge(int u, int v, int w){
       edges.push_back({u, v, w});
       g[u].push_back(ec++);
       edges.push_back({v, u, w});
       g[v].push_back(ec++);
   }

   bool level_graph(){
       level.clear();
       level.resize(n, -1);
       queue<int> q;
       q.push(source);
       level[source] = 0;
       while(!q.empty()){
           int cur = q.front();
           q.pop();
           for(auto xx : g[cur]){
               int to = edges[xx].v;
               int w = edges[xx].w;
               if(w and level[to] == -1){
                   level[to] = level[cur] + 1;
                   q.push(to);
               }
           }
       }
       return level[sink] != -1;
   }

   int augment(int cur, int flow){
       if(cur == sink)return flow;
       for(int &i = edge_sz[cur]; i >= 0; i--){
           int edge_idx = g[cur][i];
           if(edges[edge_idx].w and level[edges[edge_idx].v] == level[cur] + 1){
               int bottle_neck = augment(edges[edge_idx].v, min(flow, edges[edge_idx].w));
               if(bottle_neck){
                   edges[edge_idx].w -= bottle_neck;
                   edges[edge_idx ^ 1].w += bottle_neck;
                   return bottle_neck;
               }
           }
       }
       return 0;
   }

   int max_flow(){
       int flow = 0;
       while(level_graph()){
           for(int i = 0; i < n; i++)edge_sz[i] = g[i].size() - 1;
           while(int new_flow = augment(source, INT_MAX)){
               flow += new_flow;
           }
       }
       return flow;
   }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    Dinic G(n + 1, 1, n);
    for(int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
           if(u != v) G.add_edge(u, v, w);
    }
    cout << G.max_flow() << '\n';
    return 0;
}
