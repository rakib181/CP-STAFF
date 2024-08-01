#include<bits/stdc++.h>
using namespace std;
using ll = long long;

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
        for (idx /= 2; idx; idx /= 2) t[idx] = max(t[2 * idx], t[2 * idx + 1]);
    }

    int query(int lo, int hi) {
        int ra = 0, rb = 0;
        for (lo += n, hi += n + 1; lo < hi; lo /= 2, hi /= 2) {
            if (lo & 1) ra = max(ra, t[lo++]);
            if (hi & 1) rb = max(rb, t[--hi]);
        }
        return max(ra, rb);
    }
}st(2e5 + 9);

const int N = 2e5 + 9;
vector<int> g[N], a(N), depth(N), sz(N), top(N), id(N), parent(N);
int timer;

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
    st.upd(id[u], a[u]);
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
    int ans = 0;
    while (top[u] != top[v]){
        if(depth[top[u]] < depth[top[v]])swap(u, v);
        ans = max(ans, st.query(id[top[u]], id[u]));
        u = parent[top[u]];
    }
    if(depth[u] > depth[v])swap(u, v);
    ans = max(ans, st.query(id[u], id[v]));
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    timer = 1;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    size(1, 1);
    hld(1, 1, 1);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int s, v;
            cin >> s >> v;
            a[s] = v;
            s = id[s];
            st.upd(s, v);
        }else{
            int u, v;
            cin >> u >> v;
            cout << query(u, v) << ' ';
        }
    }
    return 0;
}
