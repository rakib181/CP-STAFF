#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
vector<int> g[N]; int n, x, a[N];

ll dfs(int cur, int par){
    ll s = a[cur];
    for(auto xx : g[cur]){
        if(xx != par){
            s += dfs(xx, cur);
        }
    }
    return max(s, 1LL * -x);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        cin >> n >> x;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            g[i].clear();
        }
        for(int i  = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cout << dfs(1, 0) << '\n';
    }
    return 0;
}
