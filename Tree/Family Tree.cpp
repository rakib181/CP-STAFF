#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<int> g[N], W(N), DP(N, INT_MIN), MX(N, INT_MIN), MN(N, INT_MAX);

void dfs(int cur, int par = -1){
    for(auto x : g[cur]){
        if(x != par){
            dfs(x, cur);
            MX[cur] = max(MX[cur], MX[x]);
            MN[cur] = min(MN[cur], MN[x]);
        }
    }
    MX[cur] = max(MX[cur], W[cur]);
    MN[cur] = min(MN[cur], W[cur]);
    DP[cur] = max({DP[cur], abs(W[cur] - MX[cur]), abs(W[cur] - MN[cur])});
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> W[i];
    }
    int root;
    for(int u = 1; u <= n; u++){
        int v;
        cin >> v;
        if(v == -1){
            root = u;
            continue;
        }
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(root);
    int ans = INT_MIN;
    for(int i = 1; i <= n; i++){
        ans = max(ans, DP[i]);
    }
    cout << ans << '\n';
    return 0;
}
