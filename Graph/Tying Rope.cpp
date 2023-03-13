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

//Another Approach
#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 5e5 + 9;
vector<int> g[N];
vector<int> vis(N, 0);

bool dfs(int cur, int par){
    vis[cur] = 1;
    for(auto x : g[cur]){
        if(!vis[x]){
            if(dfs(x, cur)) return true;
        }else if(par == -1)return true;
    }
    return false;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
       g[i].push_back(i + n);
       g[i + n].push_back(i);
    }
    for(int i = 0; i < m; i++){
        int u, v; char c, cc;
        cin >> u >> c >> v >> cc;
        if(c == 'B'){
            u += n;
        }
        if(cc == 'B'){
            v += n;
        }
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cycle = 0, non_cycle = 0;
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            if(dfs(i, -1)){
                cycle += 1;
            }else non_cycle += 1;
        }
    }
    cout << cycle << ' ' << non_cycle << '\n';
    return 0;
}
