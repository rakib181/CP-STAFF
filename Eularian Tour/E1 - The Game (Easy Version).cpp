#include<bits/stdc++.h>
using namespace std;
#define long long long int

const int N = 4e5 + 9;
int n;
vector<int> g[N], a(N), in(N), fin(N);
vector<int> t(4 * N);

int merge(int x, int y){
    return max(x, y);
}


void upd(int node, int b, int e, int l, int r, int v){
    if(b > r or e < l)return;
    if(b >= l and e <= r){
        t[node] = v;
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * node, b, m, l, r, v);
    upd(2 * node + 1, m + 1, e, l, r, v);
    t[node] = merge(t[2 * node], t[2 * node + 1]);
}

int query(int node, int b, int e, int l, int r){
    if(b > r or e < l)return 0;
    if(b >= l and e <= r)return t[node];
    int m = (b + e) >> 1;
    return merge(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
}
int tme;

void dfs(int u, int p){
    in[u] = ++tme;
    upd(1, 1, n, in[u], in[u], a[u]);
    for(auto v : g[u]){
        if(v == p)continue;
        dfs(v, u);
    }
    fin[u] = tme;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n;
        for(int i = 1; i <= n; i++){
            g[i].clear();
            in[i] = fin[i] = 0;
        }
        for(int i = 1; i <= 4 * n; i++)t[i] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        tme = 0;
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        dfs(1, 0);
        int ans = 0;
        for(int i = 1; i <= n; i++){
            int left = query(1, 1, n, 1, in[i] - 1);
            int right = query(1, 1, n, fin[i] + 1, n);
            if(max(left, right) > a[i] and a[i] > a[ans]){
                ans = i;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
