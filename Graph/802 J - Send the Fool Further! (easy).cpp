#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int N = 105;
vector<pair<int, int>> g[N];
int ans, tmp = 0;

void dfs(int cur, int par = -1){
  for(auto x : g[cur]){
      if(x.first != par){
          tmp += x.second;
          dfs(x.first, cur);
          ans = max(ans, tmp);
          tmp -= x.second;
      }
  }
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n - 1; i++){
       int u, v, wt;
       cin >> u >> v >> wt;
       g[u].emplace_back(v, wt);
       g[v].emplace_back(u, wt);
    }
    ans = 0;
    dfs(0);
    cout << ans << '\n';
    return 0;
}
