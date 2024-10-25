#include<bits/stdc++.h>
using namespace std;
#define long long long int

const int N = 2e5 + 9, inf = 1e9 + 7;
int n, q;
vector<int> g[N], ans(N), h(N);
vector<int> t(4 * N);
vector<array<int, 2>> que[N];

int merge(int x, int y){
    return max(x, y);
}

void upd(int node, int b, int e, int i, int v){
    if(b > i or e < i)return;
    if(b == e){
        t[node] = v;
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * node, b, m, i, v);
    upd(2 * node + 1, m + 1, e, i, v);
    t[node] = merge(t[2 * node], t[2 * node + 1]);
}

int query(int node, int b, int e, int l, int r){
    if(b > r or e < l)return -inf;
    if(b >= l and e <= r)return t[node];
    int m = (b + e) >> 1;
    return merge(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
}

void dfs(int u, int p){
    for(auto v : g[u]){
        if(v == p)continue;
        dfs(v, u);
        h[u] = max(h[u], h[v] + 1);
    }
}

void cal(int u, int p, int d){
    for(auto [k, i] : que[u]){
        auto f = query(1, 1, n, max(1, d - k), d - 1) + d;
        ans[i] = max(h[u], f);
    }
    int mx1 = 0, mx2 = 0, i = u;
    for(auto v : g[u]){
        if(v == p)continue;
        if(h[v] + 1 > mx1){
            mx2 = mx1, mx1 = h[v] + 1;
            i = v;
        }else{
           mx2 = max(mx2, h[v] + 1);
        }
    }
    for(auto v : g[u]){
        if(v == p)continue;
        upd(1, 1, n, d, ((i == v) ? mx2 : mx1) - d);
        cal(v, u, d + 1);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        cin >> n;
        for(int i = 0; i <= n; i++){
            g[i].clear();
            ans[i] = h[i] = 0;
            que[i].clear();
        }
        for(int i = 0; i <= 4 * n; i++){
            t[i] = 0;
        }
        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        cin >> q;
        for(int i = 1; i <= q; i++){
             int v, k;
             cin >> v >> k;
             que[v].push_back({k, i});
        }
        dfs(1, 0);
        cal(1, 0, 1);
        for(int i = 1; i <= q; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
