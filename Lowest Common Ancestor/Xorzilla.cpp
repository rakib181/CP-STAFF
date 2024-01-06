#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10, MX = 28;
vector<int> g[N];
int p[N][MX], ar[N], tme, in[N], ou[N], xor_path[N], h[N];

void dfs(int u, int par){
    in[u] = tme++;
    if(u == par){
        p[u][0] = u;
        xor_path[u] = ar[u];
    }else{
        p[u][0] = par;
        xor_path[u] = xor_path[par] ^ ar[u];
    }
    for(int i = 1; i < MX; i++){
        p[u][i] = p[p[u][i - 1]][i - 1];
    }
    for(auto v : g[u]){
        if(v != par){
            h[v] = h[u] + 1;
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
            xor_path[i] = in[i] = ou[i] = h[i] = 0;
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
        for(int i = 1; i <= n; i++)cin >> ar[i];
        tme = 1;
        dfs(1, 1);
        int q;
        cin >> q;
        while (q--) {
            int x, a, b;
            cin >> x >> a >> b;
            int lc = lca(a, b);
            int val = xor_path[a] ^ xor_path[b] ^ ar[lc];
            int d = h[a] + h[b] - 2 * h[lc] + 1;
            int ans = val, v = 0;
            if(d & 1) {
                for (int i = 30; i >= 0; i--) {
                    if (!((ans >> i) & 1)) {
                        if (((1 << i) | v) <= x) {
                            v |= (1 << i);
                        }
                    }
                }
            }
            cout << (ans ^ v) << '\n';
        }
    }
    return 0;
}
