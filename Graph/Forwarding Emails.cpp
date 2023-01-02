#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--){
        int n;
        cin >> n;
        vector<int> g[n + 1];
        vector<bool> vis;
        vector<bool> used(n + 1, false);
        for(int i = 0; i < n; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
        }
        int cnt, ans = -1, node = -1;
        function<void(int)> DFS = [&](int cur){
            vis[cur] = true;
            cnt++;
            for(auto x : g[cur]){
                if(!vis[x]){
                    DFS(x);
                }
            }
            vis[cur] = false;
            used[cur] = true;
        };
        for(int i = 1; i <= n; i++){
            vis.assign(n + 1, false);
            cnt = 0;
            if(!used[i]) {
                DFS(i);
                if (ans == -1 and node == -1) {
                    ans = cnt, node = i;
                } else if (ans < cnt) {
                    node = i, ans = cnt;
                }
            }
        }
        cout << "Case " << cs++ << ":" << ' ' << node << '\n';
    }
    return 0;
}
