#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 9;
vector<int> g[N], op(N), dp(N), col(N);

int DFS(int cur, int par){
    if(dp[cur] != 0) return dp[cur];
    dp[cur] += op[cur];
    for(auto x : g[cur]){
        if(x != par){
            dp[cur] += DFS(x, cur);
        }
    }
    return dp[cur];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> col[i];
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    while (m--){
        int x;
        cin >> x;
        op[x] += 1;
    }
    dp[1] = DFS(1, -1);
    int tot = 0;
    for(int i = 1; i <= n; i++){
        if(col[i] and !(dp[i] & 1))tot++;
        if(!col[i] and (dp[i] & 1))tot++;
    }
    cout << tot << '\n';
    return 0;
}
