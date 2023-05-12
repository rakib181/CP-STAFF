#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
vector<int> g[N];
int a[N], s, sz;
bool vis[N];

void dfs(int cur){
    vis[cur] = true;
    sz += 1;
    s += a[cur];
    for(auto x : g[cur]){
        if(!vis[x]){
            dfs(x);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, cs = 1;
    cin >> t;
    while(t--){
        cout << "Case " << cs++ << ": ";
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            g[i].clear();
            vis[i] = false;
        }
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        set<int> se; bool possible = true;
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                s = 0, sz = 0;
                dfs(i);
                if(s % sz == 0)se.insert(s / sz);
                else possible = false;
            }
        }
        ((int) se.size() == 1 and possible) ? cout << "Yes\n" : cout << "No\n";
    }
    return 0;
}
