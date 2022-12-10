#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
map<int, vector<int>> g;
vector<bool> vis(N);

int DFS(int cur){
    vis[cur] = true;
    int sz = 1;
    for(auto x : g[cur]){
        if(!vis[x]){
            sz += DFS(x);
        }
    }
    return sz;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        g.clear();
        for(int i = 1; i <= n; i++){
           vis[i] = false;
        }
        bool ok = true;
        for(int i = 1; i <= n; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v), g[v].push_back(u);
            if(u == v or g[u].size() > 2 or g[v].size() > 2)ok = false;

        }
       if(!ok){
           cout << "NO" << '\n';
       } else{
           for(int i = 1; i <= n; i++){
               if(!vis[i]){
                   if(DFS(i) % 2){
                       ok = false;
                       break;
                   }
               }
           }
           if(ok)cout << "YES" << '\n';
           else cout << "NO" << '\n';
       }
    }
    return 0;
}
