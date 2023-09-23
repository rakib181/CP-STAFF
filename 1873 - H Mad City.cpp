#include<bits/stdc++.h>
using namespace  std;
using ll = long long;
const int N = 2e5 + 9, inf = 1e9 + 7;
vector<int> g[N];
int d_a[N], d_b[N], deg[N];

void bfs(int s, int *d){
    queue<int> q;
    q.push(s);
    d[s] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto v : g[node]){
            if(d[v] == -1){
                d[v] = d[node] + 1;
                q.push(v);
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        cin >> n >> a >> b;
        for(int i = 1; i <= n; i++){
            g[i].clear();
            d_a[i] = d_b[i] = -1;
            deg[i] = 0;
        }
        for(int i = 1; i <= n; i++){
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
            deg[u] += 1, deg[v] += 1;
        }
        if(a == b){
            cout << "NO\n";
            continue;
        }
        vector<int> vis(n + 1, 0);
        queue<int> q;
        for(int i = 1; i <= n; i++){
            if(deg[i] == 1)q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            vis[node] = true;
            for(auto v : g[node]){
                deg[v] -= 1;
                if(deg[v] == 1){
                    q.push(v);
                }
            }
        }
        vector<int> node;
        for(int i = 1; i <= n; i++){
            if(!vis[i])node.emplace_back(i);
        }
        bfs(a, d_a);
        bfs(b, d_b);
        bool possible = false;
        for(auto v : node){
            possible |= (d_a[v] > d_b[v]);
        }
        cout << (possible ? "YES\n" : "NO\n");
    }
    return 0;
}
