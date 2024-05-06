#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(int u, vector<int> *g, vector<int> &s, vector<bool> &vis){
    vis[u] = true;
    for(auto v : g[u]){
        if(!vis[v]){
            dfs(v, g, s, vis);
        }
    }
    s.emplace_back(u);
}


void dfs1(int u, vector<int> *g, int c, vector<int> &comp,  vector<int> &gcd, vector<int> &C){
    comp[u] = c;
    gcd[c] = __gcd(gcd[c], C[u]);
    for(auto v : g[u]){
        if(comp[v] == -1){
            dfs1(v, g, c, comp, gcd, C);
        }
    }
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> c(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    vector<int> g[n + 1], rev[n + 1];
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        rev[v].emplace_back(u);
    }
    vector<bool> vis(n + 1, false);
    vector<int> s;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i, g, s, vis);
        }
    }
    reverse(s.begin(), s.end());
    vector<int> comp(n + 1, -1);
    int com = 0; vector<int> node; vector<int> gcd(n + 1, 0);
    for(auto v : s){
       if(comp[v] == -1) {
           int gc = 0;  node.clear();
           dfs1(v, rev, ++com, comp, gcd, c);
       }
    }
    vector<int> cond[n + 1];
    for(int i = 1; i <= n; i++){
        for(auto j : g[i]){
            if(comp[i] != comp[j]){
                cond[comp[i]].emplace_back(comp[j]);
            }
        }
    }
    s.clear();
    vis.assign(n + 1, false);
    for(int i = 1; i <= com; i++){
        if(!vis[i]){
            dfs(i, cond, s, vis);
        }
    }
    const int inf = 1e9 + 7;
    vector<set<int>> ss (n + 1);
    int ans = inf;
    while(!s.empty()){
        int cur = s.back();
        s.pop_back();
        ss[cur].insert(gcd[cur]);
        ans = min(ans, gcd[cur]);
        for(auto it = ss[cur].begin(); it != ss[cur].end(); it++){
            for(auto j : cond[cur]){
                 ss[j].insert(__gcd(*it, gcd[j]));
                 ans = min(ans, __gcd(*it, gcd[j]));
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
