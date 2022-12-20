#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 2e5 + 9;
vector<int> g[N], low(N), high(N), dp;
void DFS(int cur, int par){
    low[cur] = (int) dp.size();
    dp.push_back(cur);
    for(auto x : g[cur]){
        if(x != par){
            DFS(x, cur);
        }
    }
    high[cur] = (int) dp.size();
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for(int i = 2; i <= n; i++){
        int x;
        cin >> x;
        g[x].push_back(i);
        g[i].push_back(x);
    }
    DFS(1, -1);
    while (q--){
        int u, k;
        cin >> u >> k;
        u--, k--;
        int idx = low[u + 1] + k;
        if(idx < high[u + 1])cout << dp[idx] << '\n';
        else cout << "-1" << '\n';
    }
    return 0;
}
