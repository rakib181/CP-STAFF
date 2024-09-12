#include<bits/stdc++.h>
using namespace std;

#define long long long int

struct save{
    int u, rank_u, v, rank_v;
    save(int _u, int _rank_u, int _v, int _rank_v) : u(_u), rank_u(_rank_u), v(_v), rank_v(_rank_v) {};
};

struct dsu_rollback{
    vector<int> p, rank;
    stack<save> op;
    int components{};
     void init(int n){
        this -> components = n;
        this -> p.assign(n, 0);
        this -> rank.assign(n, 0);
        for(int i = 0; i < n; i++){
            p[i] = i;
            rank[i] = 0;
        }
    }
    int find(int u){
        if(u == p[u])return u;
        return find(p[u]);
    }
    bool unite(int u, int v){
        u = find(u), v = find(v);
        if(v == u){
            return false;
        }
        components--;
        if(rank[u] > rank[v])swap(u, v);
        op.emplace(u, rank[u], v, rank[v]);
        p[u] = v;
        if(rank[u] == rank[v]){
            rank[v]++;
        }
        return true;
    }
    void rollback(){
        if(op.empty())return;
        save x = op.top();
        op.pop();
        components++;
        p[x.u] = x.u, p[x.v] = x.v;
        rank[x.u] = x.rank_u, rank[x.v] = x.rank_v;
    }
}dsu;

struct query{
    bool united;
    int u, v;
};
const int N = 1e5 + 9;
vector<query> op[4 * N];
vector<int> ans(N);

void upd(int node, int b, int e, int l, int r, query& x){
    if(b > r or e < l)return;
    if(b >= l and e <= r){
        op[node].emplace_back(x);
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * node, b, m, l, r, x);
    upd(2 * node + 1, m + 1, e, l, r, x);
}


void dfs(int node, int b, int e){
    for(auto &[united, u, v] : op[node]){
       united = dsu.unite(u, v);
    }
    if(b == e){
        ans[b] = dsu.components;
    }else {
        int m = (b + e) >> 1;
        dfs(2 * node, b, m);
        dfs(2 * node + 1, m + 1, e);
    }
    for(auto [united, u, v] : op[node]){
       if(united) dsu.rollback();
    }
}



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, t;
    cin >> n >> m >> t;
    map<pair<int, int>, int> range;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        if(u > v)swap(u, v);
        range[{u, v}] = 0;
    }
    for(int i = 1; i <= t; i++){
        int type;
        cin >> type;
        if(type == 1){
            int u, v;
            cin >> u >> v;
            u--, v--;
            if(u > v)swap(u, v);
            range[{u, v}] = i;
        }else{
            int u, v;
            cin >> u >> v;
            u--, v--;
            if(u > v)swap(u, v);
            query x = {false, u, v};
            upd(1, 0, t, range[{u, v}], i - 1, x);
            range.erase({u, v});
        }
    }
    for(auto [x, i] : range){
        query v = {false, x.first, x.second};
        upd(1, 0, t, i, t, v);
    }
    dsu.init(n);
    dfs(1, 0, t);
    for(int i = 0; i <= t; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
