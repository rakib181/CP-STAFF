#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
vector<vector<int>> dp(N, vector<int> (2, 0));

void dfs(int cur, int par){
    dp[cur][0] = 0;
    dp[cur][1] = 1;
    for(auto x : g[cur]){
        if(x != par){
            dfs(x, cur);
            dp[cur][0] += dp[x][1];
            dp[cur][1] += min(dp[x][0], dp[x][1]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    cout << min(dp[1][0], dp[1][1])<< '\n';
    return 0;
}
