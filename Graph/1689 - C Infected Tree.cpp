#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 9;
vector<int> g[N];
int del;

void dfs(int cur, int par, int lvl){
    if(g[cur].size() == 3 or (g[cur].size() == 2 and cur == 1)){
        for(auto x : g[cur]){
           if(x != par) dfs(x, cur, lvl + 1);
        }
    }else if(g[cur].size() == 1 and cur != 1){
        del = min(del, 2 * lvl - 1);
    }else del = min(del, 2 * lvl);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++)g[i].clear();
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        del = INT_MAX;
        dfs(1, -1, 1);
        cout << n - del << '\n';
    }
    return 0;
}

// DP BASED 
#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 9;
vector<int> g[N];
vector<int> dp(N), sz(N);

void dfs(int cur, int par){
    sz[cur] = 1, dp[cur] = 0;
    vector<int> child;
    for(auto x : g[cur]){
        if(x != par){
            dfs(x, cur);
            sz[cur] += sz[x];
            child.push_back(x);
        }
    }
    if(child.size() == 1){
        dp[cur] = sz[child[0]] - 1;
    }else if(child.size() == 2){
        dp[cur] = sz[child[0]] - 1 + dp[child[1]];
        dp[cur] = max(dp[cur], sz[child[1]] - 1 + dp[child[0]]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++)g[i].clear(), dp[i] = 0;
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1, -1);
        cout << dp[1] << '\n';
    }
    return 0;
}
