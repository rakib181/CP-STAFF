#include <bits/stdc++.h>
using namespace std;
#define int long long int
int n;
vector<vector<int>> g;
vector<int> potentials, ans, sz;

void dfs(int cur, int par){
    for(auto x : g[cur]){
        if(x != par){
            dfs(x, cur);
            sz[cur]++;
            if(sz[x] == 0){
                potentials[cur] += (x % 2);
            }else{
                potentials[cur] += (potentials[x] != 0);
            }
        }
    }
}

void cal(int cur, int par){
    if(par != -1){
        sz[par]--;
        if(sz[cur] == 0){
            potentials[par] -= (cur % 2);
        }else potentials[par] -= (potentials[cur] != 0);
        sz[cur]++;
        if(sz[par] == 0){
            potentials[cur] += (par % 2);
        }else potentials[cur] += (potentials[par] != 0);
        ans[cur] = potentials[cur];
    }
    for(auto x : g[cur]){
        if(x != par){
            cal(x, cur);
        }
    }
    if(par != -1){
        sz[cur]--;
        if(sz[par] == 0){
            potentials[cur] -= (par  % 2);
        }else potentials[cur] -= (potentials[par] != 0);
        sz[par]++;
        if(sz[cur] == 0){
            potentials[par] += (cur % 2);
        }else potentials[par] += (potentials[cur] != 0);
    }
}

signed main(){
     ios_base::sync_with_stdio(false);
     cin.tie(nullptr);
     int tt;
     cin >> tt;
    while (tt--) {
        cin >> n;
        g.clear();
        g.assign(n, vector<int>());
        potentials.assign(n, 0), ans.assign(n, 0), sz.assign(n, 0);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0, -1);
        ans[0] = potentials[0];
        cal(0, -1);
        for (int i = 0; i < n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
     return 0;
}
