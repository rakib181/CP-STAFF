#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 10010;
vector<int> g[N];
vector<bool> vis(N);

void TOPO(int cur, vector<int> &top){
    vis[cur] = true;
    for(auto x : g[cur]){
        if(!vis[x]){
            TOPO(x, top);
        }
    }
    top.push_back(cur);
}

void DFS(int cur){
    vis[cur] = true;
    for(auto x : g[cur]){
        if(!vis[x]){
            DFS(x);
        }
    }
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--) {
        cout << "Case " << cs++ << ": ";
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
        }
        vector<int> topo;
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                TOPO(i, topo);
            }
        }
        reverse(topo.begin(), topo.end());
        for(int i = 1; i <= n; i++){
            vis[i] = false;
        }
        int tot = 0;
        for(int i = 0; i < (int) topo.size(); i++){
            if(!vis[topo[i]]){
                DFS(topo[i]);
                tot++;
            }
        }
        cout << tot << '\n';
        for (int i = 0; i < N; i++) {
            g[i].clear();
            vis[i] = false;
        }
    }
    return 0;
}
