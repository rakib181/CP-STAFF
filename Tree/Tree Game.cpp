#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 5005;
vector<int> g[N], P;
int x, y;

int dfs(int u, int v, int sa, int sb, int pa, int pb, int score){
      sa += P[u], sb += P[v]; score += (sa > sb);
      if(((int) g[u].size() == 1 and u != x) or ((int) g[v].size() == 1) and v != y){
         return score;
      }
      int res = 0;
      for(auto xx : g[u]){
          if(xx == pa)continue;
          int cur = LONG_LONG_MAX;
          for(auto yy : g[v]){
              if(yy != pb){
                  cur = min(cur, dfs(xx, yy, sa, sb, u, v, score));
              }
          }
          res = max(res, cur);
      }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
       for(auto & i : g){
           i.clear();
       }
       int n;
       cin >> n >> x >> y;
       P.resize(n + 1);
       for(int i = 1; i <= n; i++){
           cin >> P[i];
       }
       for(int i = 0; i < n - 1; i++){
           int u, v;
           cin >> u >> v;
           g[u].push_back(v);
           g[v].push_back(u);
       }
       cout << dfs(x, y, 0, 0, -1, -1, 0) << '\n';
    }
    return 0;
}
