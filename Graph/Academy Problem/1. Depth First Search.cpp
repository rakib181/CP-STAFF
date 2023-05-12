#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 105;
vector<int> g[N]; int timer;
vector<bool> vis(N);
int st[N], en[N];

void dfs(int cur){
    vis[cur] = true;
    st[cur] = ++timer;
    for(auto x : g[cur]){
        if(!vis[x]){
            dfs(x);
        }
    }
    en[cur] = ++timer;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int u, c;
        cin >> u >> c;
        while(c--){
            int v;
            cin >> v;
            g[u].emplace_back(v);
        }
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    for(int i = 1; i <= n; i++){
        cout << i << ' ' << st[i] << ' ' << en[i] << '\n';
    }
    return 0;
}
