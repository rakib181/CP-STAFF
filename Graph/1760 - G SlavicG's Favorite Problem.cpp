#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 1e5 + 9;
vector<pair<int, int>> g[N];
map<int, bool> seen;

void DFS1(int cur, int par, int x, int b){
    if(cur == b)return;
    seen[x] = true;
    for(auto xx : g[cur]){
        if(xx.first != par){
            DFS1(xx.first, cur, x ^ xx.second, b);
        }
    }
}

bool DFS2(int cur, int par, int x, int b){
    if(seen[x] and cur != b)return true;
    for(auto xx : g[cur]){
        if(xx.first != par){
           bool sub = DFS2(xx.first, cur, x ^ xx.second, b);
            if(sub)return true;
        }
    }
    return false;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
       int n, a, b;
       cin >> n >> a >> b;
       seen.clear();
       for(int i = 0; i <= n + 1; i++){
           g[i].clear();
       }
       for(int i = 0; i < n - 1; i++){
           int u, v, wt;
           cin >> u >> v >> wt;
           g[u].emplace_back(v, wt);
           g[v].emplace_back(u, wt);
       }
       DFS1(a, -1, 0, b);
      if(DFS2(b, -1, 0, b)) cout << "YES" << '\n';
      else cout << "NO" << '\n';
    }
    return 0;
}
