#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 2e5 + 9;
vector<int> g[N];
vector<int> std_path(N), other(N);
int n, k, x, y;

void DFS(int cur, int par){
    for(auto xx : g[cur]){
        if(xx != par){
            DFS(xx, cur);
            if(std_path[xx]){
                std_path[cur] = 1;
            }
            if(other[xx]){
                other[cur] = 1;
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
      cin >> n >> k >> x >> y;
      for(int i = 1; i <= n; i++){
          g[i].clear();
          std_path[i] = 0;
          other[i] = 0;
      }
      std_path[y] = 1;
      for(int i = 0; i < k; i++){
          int xx;
          cin >> xx;
          other[xx] = 1;
      }
      for(int i = 0; i < n - 1; i++){
          int u, v;
          cin >> u >> v;
          g[u].push_back(v);
          g[v].push_back(u);
      }
      DFS(x, -1);
      int ans = 0;
      for(int i = 1; i <= n; i++){
          if(i == x)continue;
          if(std_path[i])ans += 1;
          else if(other[i])ans += 2;
      }
      cout << ans << '\n';
    }
    return 0;
}
