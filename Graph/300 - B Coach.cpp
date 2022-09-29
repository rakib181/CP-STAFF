#include<bits/stdc++.h>
using namespace std;

const int N = 50;
vector<int> g[N];
vector<bool> vis(N, false);
vector<int> path;

void dfs(int cur){
    path.push_back(cur);
    vis[cur] = true;
    for(auto x : g[cur]){
        if(!vis[x])dfs(x);
    }
}

int32_t main(){
     ios_base::sync_with_stdio(0);
      cin.tie(0);
      int n, m;
      cin >> n >> m;
      for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
      }
      vector<vector<int>> grp_o;
      vector<vector<int>> grp_tw;
      vector<vector<int>> grp_th;
      bool ok = true;
      for(int i = 1; i <= n; i++){
           path.clear();
           if(!vis[i]){
            dfs(i);
           }
           if(path.size() > 3){
            ok = false;
            break;
            }
           if(path.size() == 3)grp_th.push_back(path);
           else if(path.size() == 2)grp_tw.push_back(path);
           else if(path.size() == 1) grp_o.push_back(path);
           path.clear();
      }
      if(grp_tw.size() > grp_o.size())ok = false;
      if(grp_tw .size() < grp_o.size()){
          if(((grp_o.size() - grp_tw.size()) % 3) != 0)ok = false;
      }
      if(!ok)cout << "-1" << '\n';
      else{
        if(!grp_th.empty()){
        for(auto x : grp_th){
            for(auto i : x){
                cout << i << ' ';
            }
            cout << '\n';
        }
        }
        int idx = 0;
        if(!grp_tw.empty()){
        for(auto x : grp_tw){
            for(auto i : x){
                cout << i << ' ';
            }
            for(int k = idx; k < grp_o.size(); k++){
                for(auto y : grp_o[k]){
                    cout << y << ' ';
                    break;
                }
                break;
            }
            idx++;
            cout << '\n';
         }
       }
        if(grp_o.size() > grp_tw.size()){
            for(int i = idx; i < grp_o.size(); i++){
                for(int j = 0; j < 1; j++){
                    cout << grp_o[i][j] << ' ';
                    if(i and (i % 3) == 1)cout << '\n';
                }
            }

        }
      }
      return 0;
}

