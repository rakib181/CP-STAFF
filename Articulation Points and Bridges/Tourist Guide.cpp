#include <bits/stdc++.h>
using namespace std;
const int N = 105;
vector<int> g[N], in(N), low(N);
vector<bool> vis(N);
map<string, int> mp; int timer;
map<int, string> mp1;
set<string> art_point;

void dfs(int cur, int par){
    vis[cur] = true;
    in[cur] = low[cur] = timer++;
    int child = 0;
    for(auto x : g[cur]){
        if(x == par)continue;
        if(!vis[x]){
            dfs(x, cur);
            child++;
            low[cur] = min(low[cur], low[x]);
            if(low[x] >= in[cur] and par != -1){
                art_point.insert(mp1[cur]);
            }
        }else{
            low[cur] = min(low[cur], in[x]);
        }
    }
    if(child > 1 and par == -1)art_point.insert(mp1[cur]);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, cs = 1;
    while (cin >> n){
        if(!n)break;
      mp.clear(); timer = 1; mp1.clear(); art_point.clear();
      for(int i = 0; i < N; i++){
          g[i].clear();
          in[i] = low[i] = 0;
          vis[i] = false;
      }
      for(int i = 1; i <= n; i++){
          string s;
          cin >> s;
          mp[s] = i;
          mp1[i] = s;
      }
      int m;
      cin >> m;
        string ss, sss;
        while (m--){
            cin >> ss >> sss;
            g[mp[ss]].push_back(mp[sss]);
            g[mp[sss]].push_back(mp[ss]);
        }
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                dfs(i, -1);
            }
        }
        if (cs != 1) cout << '\n';
        cout << "City map #" << cs++ << ": "
             << (int)art_point.size() << " camera(s) found" << '\n';
        for(const auto& x : art_point){
           cout << x << '\n';
        }
    }
    return 0;
}
