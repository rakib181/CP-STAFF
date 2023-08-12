#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e3 + 9;
vector<int> g[N];
int res, sz[N];

int f(int i, int s, vector<int> &node, vector<vector<int>> &dp, int tot) {
    if(i == (int) node.size()){
        return (tot - s) * s;
    }
    int &ans = dp[i][s];
    if(ans != -1)return ans;
    ans = f(i + 1, s, node, dp, tot);
    ans = max(ans, f(i + 1, s + node[i], node, dp, tot));
    return ans;
}

void dfs(int u, int p){
    vector<int> node;
    sz[u] = 1;
    for(auto v: g[u]){
        if(v != p){
            dfs(v, u);
            sz[u] += sz[v];
            node.emplace_back(sz[v]);
        }
    }
    int n = (int) node.size();
    vector<vector<int>> dp(n, vector<int> (sz[u] + 1, -1));
    res += f(0, 0, node, dp, sz[u] - 1);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++){
        int p;
        cin >> p;
        g[p].emplace_back(i);
        g[i].emplace_back(p);
    }
    dfs(1, -1);
    cout << res << '\n';
    return 0;
}
