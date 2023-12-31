#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 8e4 + 10, MX = 23;
vector<int> g[N];
int p[N][MX], a[N], tme, in[N], ou[N];
ll t[4 * N];

ll merge(ll x, ll y) {
    return x + y;
}

void upd(int node, int b, int e, int i, int v) {
    if (b > i or e < i)return;
    if (b == e) {
        t[node] = v;
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * node, b, m, i, v);
    upd(2 * node + 1, m + 1, e, i, v);
    t[node] = merge(t[2 * node], t[2 * node + 1]);
}

ll query(int node, int b, int e, int l, int r) {
    if (b > r or e < l)return 0;
    if (b >= l and e <= r)return t[node];
    int m = (b + e) >> 1;
    return merge(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
}

void dfs(int u, int par){
    in[u] = tme++;
    if(u == par){
        p[u][0] = u;
    }else{
        p[u][0] = par;
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


signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while(tt--){
        cout << "Case " << cs++ << ":\n";
        int n;
        cin >> n; tme = 1;
        for(int i = 1; i <= n; i++){
            g[i].clear();
            in[i] = ou[i] = 0;
            for(int j = 0; j < MX; j++){
                p[i][j] = 0;
            }
        }
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            u += 1, v += 1;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        dfs(1, 1);
        for(int i = 1; i <= 4 * tme; i++){
            t[i] = 0;
        }
        for(int i = 1; i <= n; i++){
            upd(1, 1, tme, in[i], a[i]);
            upd(1, 1, tme, ou[i], -a[i]);
        }
        int q;
        cin >> q;
        while(q--){
            int type;
            cin >> type;
            if(type == 0){
                int u, v;
                cin >> u >> v;
                u += 1, v += 1;
                int lc = lca(u, v);
                ll ans = query(1, 1, tme, 1, in[u]) + query(1, 1, tme, 1, in[v]);
                ans = ans - 2LL * query(1, 1, tme, 1, in[lc]) + a[lc];
                cout << ans << '\n';
            }else{
                int i, v;
                cin >> i >> v;
                i += 1;
                upd(1, 1, tme, in[i], -a[i]);
                upd(1, 1, tme, in[i], a[i]);
                a[i] = v;
                upd(1, 1, tme, in[i], v);
                upd(1, 1, tme, ou[i], -v);
            }
        }
    }
	return 0;
}
