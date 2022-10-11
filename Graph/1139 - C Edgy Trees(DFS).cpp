#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7, N = 1e5 + 9;
vector<int> g[N];
vector<bool> vis(N, false);
int sz;


int pow(int a, int b){
    int ans = 1LL;
    while(b){
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1LL;
    }
    return ans;
}

void dfs(int cur){
    if(vis[cur]) {
        return;
    }
    vis[cur] = true;
    sz++;
    for(auto x : g[cur]){
            dfs(x);
    }
}

int32_t main(){
    int n, k, ans;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)g[i].clear(), vis[i] = false;
    ans = pow(n, k);
    for(int i = 1; i < n; i++){
        int u, v, x;
        cin >> u >> v >> x;
        if(!x)g[u].push_back(v), g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        sz = 0;
       dfs(i);
       ans -= pow(sz, k),
       ans = (ans + mod) % mod;
    }
    cout << ans << '\n';
    return 0;
}
