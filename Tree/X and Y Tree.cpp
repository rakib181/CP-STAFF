#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
       int n;
       cin >> n;
        vector<vector<int>> g (n + 1);
        vector<int> unchanged(n + 1, 0), P(n + 1, 0), val(n + 1, 0);
       for(int i = 0; i < n - 1; i++){
           int u, v;
           cin >> u >> v;
           g[u].push_back(v);
           g[v].push_back(u);
       }
      function<void(int , int)> DFS= [&](int cur, int par){
           P[cur] = par;
           for(auto x : g[cur]){
               if(x != par){
                   DFS(x, cur);
                   ++unchanged[cur];
               }
           }
       };
       DFS(1, -1);
       int q, ans = n - 1;
       cin >> q;
        while (q--){
            int type;
            cin >> type;
            if(type == 1){
                int u;
                cin >> u;
                if(!val[u] and !unchanged[u]){
                    val[u] = 1;
                    ans--;
                    if(u == 1)ans = n - 1;
                    else --unchanged[P[u]];
                }
            }else cout << ans << '\n';
        }
    }
    return 0;
}
