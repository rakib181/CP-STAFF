#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct flow_edge{
    int u, v;
    ll cap, flow = 0;
    flow_edge(int u, int v, ll w){
        this -> u = u;
        this -> v = v;
        this -> cap = w;
    }
};

struct Dinic{
    const ll flow_inf = 1e18 + 9;
    vector<flow_edge> edges;
    vector<vector<int>> g;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;
    Dinic(int n, int s, int t){
        this -> n = n;
        this -> s = s;
        this -> t = t;
        this -> g.resize(n);
        this -> level.resize(n);
        this -> ptr.resize(n);
    }

    void add_edge(int u, int v, ll w){
        edges.emplace_back(u, v, w);
        edges.emplace_back(v, u, 0);
        g[u].emplace_back(m);
        g[v].emplace_back(m + 1);
        m += 2;
    }

    bool bfs(){
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            for(auto id : g[u]){
                int v = edges[id].v;
                if(edges[id].cap - edges[id].flow < 1){
                    continue;
                }
                if(level[v] != -1){
                    continue;
                }
                level[v] = level[u] + 1;
                q.emplace(v);
            }
        }
        return level[t] != -1;
    }

    ll dfs(int u, ll pushed){
        if(pushed == 0){
            return 0;
        }
        if(u == t){
            return pushed;
        }
        for(auto &cid = ptr[u]; cid < (int) g[u].size(); cid++){
            int id = g[u][cid];
            int v = edges[id].v;
            if(level[u] + 1 != level[v] or (edges[id].cap - edges[id].flow < 1)){
                continue;
            }
            ll tr = dfs(v, min(pushed, edges[id].cap - edges[id].flow));
            if(tr == 0){
                continue;
            }
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    ll flow(){
        ll f = 0;
        while(true){
            level.assign(n, -1);
            level[s] = 0;
            q.push(s);
            bfs();
            if(!bfs()){
                break;
            }
            fill(ptr.begin(), ptr.end(), 0);
            while(ll pushed = dfs(s, flow_inf)){
                f += pushed;
            }
        }
        return f;
    }
};


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    Dinic din(n, 0, n - 1);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        din.add_edge(u, v, w);
    }
    cout << din.flow() << '\n';
    return 0;
}
