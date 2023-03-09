#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 3e5 + 9, MOD = 1e9 + 7;
vector<int> g[N]; int tot;

int dfs(int cur, int par){
    int sz = 1;
    for(auto x : g[cur]){
        if(x != par){
            sz = (sz * (dfs(x, cur) + 1)) % MOD;
        }
    }
    tot = ((tot % MOD) + (sz % MOD)) % MOD;
    return sz;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    cout << tot + 1 << '\n';
    return 0;
}
