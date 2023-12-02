#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 9;
vector<pair<int, int>> g[N];
int in[N], low[N], a[N], tme;
bool vis[N];
vector<int> x;

void dfs(int u, int p){
    vis[u] = true;
    in[u] = low[u] = tme++;
    for(auto [v, w] : g[u]){
        if(v == p)continue;
        if(!vis[v]){
            dfs(v, u);
            if(low[v] > in[u]){
                x.emplace_back(w);
            }
            low[u] = min(low[u], low[v]);
        }else{
            low[u] = min(low[u], in[v]);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
     int n, m;
     cin >> n >> m;
     for(int i = 1; i <= m; i++)cin >> a[i];
     for(int i = 1; i <= m; i++){
         int u, v;
         cin >> u >> v;
         g[u].emplace_back(v, a[i]);
         g[v].emplace_back(u, a[i]);
     }
     tme = 1;
     dfs(1, 0);
     sort(x.begin(), x.end());
     ll mn = 0;
     for(int i = (int) x.size() - 2; i >= 0; i -= 2){
         mn += x[i];
     }
     ll mx = 0;
     for(int i = (int) x.size() - 1; i >= 0; i -= 2){
         mx += x[i];
     }
     cout << mx << ' ' << mn << '\n';
    return 0;
}
