#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 1e9 + 7;

struct segment_tree{
    vector<int> t;
    int n{};
    segment_tree() = default;
    explicit segment_tree(int _n){
        this -> n = _n;
        t.assign(2 * n, 0);
    }
    void upd(int idx, int val) {
        t[idx += n] = val;
        for (idx /= 2; idx; idx /= 2) t[idx] = min(t[2 * idx], t[2 * idx + 1]);
    }

    int query(int lo, int hi) {
        int ra = inf, rb = inf;
        for (lo += n, hi += n + 1; lo < hi; lo /= 2, hi /= 2) {
            if (lo & 1) ra = min(ra, t[lo++]);
            if (hi & 1) rb = min(rb, t[--hi]);
        }
        return min(ra, rb);
    }
}st(3e5 + 9);

const int N = 3e5 + 9;
vector<int> g[N], depth(N), sz(N), top(N), id(N), parent(N);
int timer;
map<pair<int, int>, int> cost;

void size(int u, int p){
    sz[u] = 1;
    parent[u] = p;
    for(auto v : g[u]){
        if(v == p)continue;
        depth[v] = depth[u] + 1;
        size(v, u);
        sz[u] += sz[v];
    }
}

void hld(int u, int p, int tp){
    id[u] = timer++;
    top[u] = tp;
    int w = cost.count({p, u}) ? cost[{p, u}] : inf;
    st.upd(id[u], w);
    int mx_sub_size = -1, node = -1;
    for(auto v : g[u]){
        if(v == p)continue;
        if(mx_sub_size < sz[v]){
            mx_sub_size = sz[v];
            node = v;
        }
    }
    if(mx_sub_size == -1)return;
    hld(node, u, tp);
    for(auto v : g[u]){
        if(v == p or v == node)continue;
        hld(v, u, v);
    }
}

int query(int u, int v){
    int ans = inf;
    while (top[u] != top[v]){
        if(depth[top[u]] < depth[top[v]])swap(u, v);
        ans = min(ans, st.query(id[top[u]], id[u]));
        u = parent[top[u]];
    }
    if(depth[u] > depth[v])swap(u, v);
    ans = min(ans, st.query(id[u] + 1, id[v]));
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    timer = 1;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        cost[{u, v}] = w;
        cost[{v, u}] = w;
    }
    size(1, 1);
    hld(1, 1, 1);
    int q;
    cin >> q;
    while(q--){
       int u, v;
       cin >> u >> v;
       cout << query(u, v) << '\n';
    }
    return 0;
}
