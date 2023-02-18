#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1005;
vector<int> g[N];
vector<bool> vis(N);


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        for(int i = 0; i < N; i++){
            g[i].clear();
            vis[i] = false;
        }
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < m; i++){
            int u, v, w = 6;
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        int src;
        cin >> src;
        queue<int> q;
        vector<int> dist(n + 1, 0);
        dist[src] = 0;
        vis[src] = true;
        q.push(src);
        while (!q.empty()){
            int node = q.front();
            q.pop();
            for(auto x : g[node]){
                if(!vis[x]){
                    vis[x] = true;
                    dist[x] += dist[node] + 6;
                    q.push(x);
                }
            }
        }
        for(int i = 1; i <= n; i++){
            if(i == src)continue;
            if(dist[i])cout << dist[i] << ' ';
            else cout << "-1" << ' ';
        }
        cout << '\n';
    }
    return 0;
}
