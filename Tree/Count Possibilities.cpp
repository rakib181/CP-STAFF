#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
vector<int> g[N];
int n, prefix[N], dep[N], sub[N], ind[N];

void dfs(int u, int p){
    sub[u] = 1;
    dep[u] = dep[p] + 1;
    for(auto v : g[u]){
        if(v != p){
            dfs(v, u);
            sub[u] += sub[v];
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
       cin >> n;
       for(int i = 0; i <= n; i++){
           g[i].clear();
           prefix[i] = dep[i] = sub[i] = ind[i] = 0;
       }
       for(int i = 1; i <= n - 1; i++){
           int u, v;
           cin >> u >> v;
           g[u].emplace_back(v);
           ind[v] += 1;
       }
       int root = 0;
       for(int i = 1; i <= n; i++){
           if(ind[i] == 0)root = i;
       }
       dfs(root, 0);
       for(int i = 1; i <= n; i++){
           prefix[dep[i]] += 1;
           prefix[n - sub[i] + 2] -= 1;
       }
       for(int i = 2; i <= n; i++){
           prefix[i] += prefix[i - 1];
       }
       for(int i = 1; i <= n; i++){
           cout << prefix[i] << ' ';
       }
       cout << '\n';
    }
    return 0;
}
