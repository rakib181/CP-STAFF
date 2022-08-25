#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
vector<int> g[N];
vector<bool> vis(N, false);
vector<int> dist(N, 0), lvl(N, 0);

void bfs(int cur){
    queue<int> q;
    vis[cur] = true;
    q.push(cur);
    dist[cur] = 0;

    while(!q.empty()){
        int src = q.front();
        q.pop();
        for(auto x : g[src]){
            if(!vis[x]){
              dist[x] = dist[src] + 1;
              vis[x] = true;
              lvl[dist[x]]++;
              q.push(x);
            }
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int q;
    cin >> q;
    while(q--){
        int src, dis;
        cin >> src >> dis;
        for(int i = 0; i < N; i++)lvl[i] = 0, vis[i] = false;
        bfs(src);
        cout << lvl[dis] << '\n';
    }
    return 0;
}
