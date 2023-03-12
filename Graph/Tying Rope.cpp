#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 2e5 + 9;
vector<int> g[N], deg(N);
vector<bool> vis(N);

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v; char c;
        cin >> u >> c >> v >> c;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[v] += 1, deg[u] += 1;
    }
    int cycle = 0, not_cycle = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i] = true; bool cyc = true;
            while (!q.empty()){
                int node = q.front();
                q.pop();
                if(deg[node] != 2)cyc = false;
                for(auto x : g[node]){
                    if(!vis[x]){
                        vis[x] = true;
                        q.push(x);
                    }
                }
            }
            if(cyc) cycle += 1;
            else not_cycle += 1;
        }
    }
    cout << cycle << ' ' << not_cycle << '\n';
    return 0;
}
