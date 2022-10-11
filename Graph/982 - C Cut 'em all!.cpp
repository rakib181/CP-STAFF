#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 9;
vector<int> g[N];
int ans;


int dfs(int cur, int par){
   int sz = 1;
    for(auto x : g[cur]){
          if(x != par) sz +=  dfs(x, cur);
    }
    if(!(sz & 1)){
        ans++;
        sz = 0;
    }
    return sz;
}

int32_t main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)g[i].clear();
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans = -1;
    dfs(1, 0);
       if(n & 1) cout << "-1" << '\n';
       else cout << ans << '\n';
    return 0;
}
