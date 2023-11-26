#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9, MX = 25;
vector<int> g[N];
int in[N], ou[N], t[8 * N], tme, pos[N], depth[N], p[N][MX];

void dfs(int u, int par){
    in[u] = ++tme;
    p[u][0] = par;
    for(int i = 1; i < MX; i++){
        p[u][i] = p[p[u][i - 1]][i - 1];
    }
    for(auto v : g[u]){
        if(v != par){
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
    ou[u] = ++tme;
}

int lca(int u, int v){
    if(depth[u] < depth[v])swap(u, v);
    int dis = depth[u] - depth[v];
    for(int i = 0; i < MX; i++){
        if((dis >> i) & 1){
            u = p[u][i];
        }
    }
    if(u == v)return u;
    for(int i = MX - 1; i >= 0; i--){
        if(p[u][i] != p[v][i]){
            u = p[u][i], v = p[v][i];
        }
    }
    return p[u][0];
}

struct fenwick{
    int n;
    vector<int> tree;
    fenwick(int n){
        this -> n = n + 5;
        tree.assign(this -> n, 0);
    }
    void upd(int idx, int val){
        while(idx <= n){
            tree[idx] += val;
            idx += (idx & -idx);
        }
    }
    int sum(int idx){
        int ans = 0;
        while(idx){
            ans += tree[idx];
            idx -= (idx & -idx);
        }
        return ans;
    }
    int query(int l, int r){
        return sum(r) - sum(l - 1);
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int n, q;
        cin >> n >> q;
        for(int i = 0; i <= 4 * n; i++)t[i] = 0;
        for(int i = 0; i <= n; i++){
            g[i].clear();
            in[i] = ou[i] = depth[i] = 0;
            for(int j = 0; j < MX; j++){
                p[i][j] = 0;
            }
        }
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            pos[x] = i;
        }
        tme = 0;
        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        dfs(1, 0);
        vector<tuple<int, int, int>> queries[n + 1];
        for(int i = 0; i < q; i++){
            int x, y, k;
            cin >> x >> y >> k;
            queries[k].emplace_back(x, y, i);
        }
        fenwick fn(2 * n + 2);
        vector<int> ans(q);
        for(int k = 1; k <= n; k++){
            for(int i = k; i <= n; i += k){
                fn.upd( in[pos[i]], +1);
                fn.upd( ou[pos[i]], -1);
            }
            for(auto [x, y, idx] : queries[k]){
                int lc = lca(x, y);
                int cnt = fn.query( 1, in[x]) + fn.query(1, in[y]) - 2 * fn.query( 1, in[lc]) +
                        fn.query( in[lc], in[lc]);
                ans[idx] = cnt;
            }
            for(int i = k; i <= n; i += k){
                fn.upd( in[pos[i]], -1);
                fn.upd( ou[pos[i]], +1);
            }
        }
        for(int i = 0; i < q; i++){
            cout << ans[i] << '\n';
        }
    }
    return 0;
}
