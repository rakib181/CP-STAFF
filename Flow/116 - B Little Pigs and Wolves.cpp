//Edmond Karp
#include <bits/stdc++.h>
using namespace std;
int n, m;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
vector<vector<int>> g;
int s, t, flow;

void BFS(vector<int> &parent){
    queue<int> q;
    q.push(s);
    vector<bool> vis(n * m + 2, false);
    vis[s] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i = 0; i < n * m + 2; i++){
            if(!vis[i] and g[node][i] == 1){
                vis[i] = true;
                q.push(i);
                parent[i] = node;
            }
        }
    }
}

void Edmond_Karp(){
    while(true){
        vector<int> parent(n * m + 2, -1);
        BFS(parent);
        if(parent[t] == -1)break;
        int tt = t;
        while(true){
            int u = parent[tt];
            g[u][tt]--;
            g[tt][u]++;
            tt = u;
            if(tt == s)break;
        }
        flow++;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    g.resize(n * m + 2, vector<int> (n * m + 2, 0));
    s = n * m, t = s + 1;
    vector<vector<char>> grid(n, vector<char> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'P'){
                g[i * m + j][t] = 1;
            }else if(grid[i][j] == 'W'){
                g[s][i * m + j] = 1;
                for(int k = 0; k < 4; k++){
                    int nx = i + dx[k], ny = j + dy[k];
                    if(nx < 0 or nx >= n or ny < 0 or ny >= m or grid[nx][ny] != 'P')continue;
                        g[i * m + j][nx * m + ny] = 1;
                }
            }
        }
    }
    flow = 0;
    Edmond_Karp();
    cout << flow << '\n';
    return 0;
}

// Dinic Algorithm

#include <bits/stdc++.h>
using namespace std;

#define int long long int
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

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
       edges.push_back({v, u, 0});
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
    Dinic G(n * m + 2, n * m, n * m + 1);
    vector<vector<char>> grid(n + 1, vector<char> (m + 1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'P'){
                G.add_edge(i * m + j, G.sink, 1);
            }else if(grid[i][j] == 'W'){
                G.add_edge(G.source, i * m + j, 1);
                for(int k = 0; k < 4; k++){
                    int nx = i + dx[k], ny = j + dy[k];
                    if(nx < 0 or nx >= n or ny < 0 or ny >= m or grid[nx][ny] != 'P')continue;
                    G.add_edge(i * m + j, nx * m + ny, 1);
                }
            }
        }
    }
    cout << G.max_flow() << '\n';
    return 0;
}
