#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int N = 1e5 + 9, mod = 1e9 + 7;
vector<int> g[N], b_e[N];
vector<int> ind(N, 0), dp(N, 0);

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        b_e[v].push_back(u);
        ind[v]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(!ind[i])q.push(i);
    }
    dp[1] = 1;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        for(auto x : g[node]){
            --ind[x];
            if(ind[x] == 0){
                q.push(x);
            }
        }
        for(auto y : b_e[node]){
            dp[node] = (dp[node] + dp[y]) % mod;
        }
    }
    cout << dp[n] << '\n';
    return 0;
}
