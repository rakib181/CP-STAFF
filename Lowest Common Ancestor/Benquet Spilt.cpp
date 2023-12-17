#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 10, MX = 23;
vector<int> g[N];
int p[N][MX], tme, in[N], ou[N], depth[N];

void dfs(int u, int par){
    in[u] = tme++;
    if(u == par){
        p[u][0] = u;
        depth[u] = 0;
    }else{
        p[u][0] = par;
        depth[u] += depth[par] + 1;
    }
    for(int i = 1; i < MX; i++){
        p[u][i] = p[p[u][i - 1]][i - 1];
    }
    for(auto v : g[u]){
        if(v != par){
            dfs(v, u);
        }
    }
    ou[u] = tme++;
}

bool ancestor(int u, int v){
    if((in[u] <= in[v] and ou[u] >= ou[v]) or u == v)return true;
    return false;
}

int lca(int u, int v){
    if(ancestor(u, v))return u;
    if(ancestor(v, u))return v;
    for(int i = MX - 1; i >= 0; i--){
        if(!ancestor(p[u][i], v)){
            u = p[u][i];
        }
    }
    return p[u][0];
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            g[i].clear();
            depth[i] = in[i] = ou[i] = 0;
            for(int j = 0; j < MX; j++){
                p[i][j] = 0;
            }
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        tme = 1;
        dfs(1, 1);
        int q;
        cin >> q;
        while (q--) {
            int x, y;
            cin >> x >> y;
            int lc = lca(x, y);
            int len = depth[x] + depth[y] - 2 * depth[lc] + 1;
            if (len & 1) {
                cout << "No\n1 " << len << '\n';
            } else {
                cout << "Yes\n";
            }
        }
    }
    return 0;
}
