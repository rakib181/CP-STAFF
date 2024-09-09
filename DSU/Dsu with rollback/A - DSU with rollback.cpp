#include<bits/stdc++.h>
using namespace std;


struct dsu_save {
    int u{}, rank_u{}, v{}, rank_v{};

    dsu_save() = default;

    dsu_save(int _u, int _rank_u, int _v, int _rank_v)
            : u(_u), rank_u(_rank_u), v(_v), rank_v(_rank_v) {}
};

struct dsu_with_rollbacks {
    vector<int> p, rnk;
    int comps{};
    stack<dsu_save> op;
    stack<int> until;

    dsu_with_rollbacks() = default;

    explicit dsu_with_rollbacks(int n) {
        p.resize(n);
        rnk.resize(n);
        for (int i = 0; i < n; i++) {
            p[i] = i;
            rnk[i] = 0;
        }
        comps = n;
    }

    int find_set(int u) {
        return (u == p[u]) ? u : find_set(p[u]);
    }

    bool unite(int u, int v) {
        u = find_set(u);
        v = find_set(v);
        if (u == v)
            return false;
        comps--;
        if (rnk[u] > rnk[v])
            swap(u, v);
        op.emplace(u, rnk[u], v, rnk[v]);
        p[u] = v;
        if (rnk[u] == rnk[v])
            rnk[v]++;
        return true;
    }

    void rollback() {
        if (op.empty())
            return;
        dsu_save x = op.top();
        op.pop();
        comps++;
        p[x.u] = x.u;
        rnk[x.u] = x.rank_u;
        p[x.v] = x.v;
        rnk[x.v] = x.rank_v;
    }
    void persist(){
        while(until.top() != -1){
            rollback();
            until.pop();
        }
        until.pop();
    }
};


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    dsu_with_rollbacks dsu(n);
    while(q--){
        string s;
        cin >> s;
        if(s == "persist"){
            dsu.until.emplace(-1);
        }else if(s == "rollback"){
            dsu.persist();
            cout << dsu.comps << '\n';
        }else{
            int u, v;
            cin >> u >> v;
            u--, v--;
            if(dsu.unite(u, v)){
                dsu.until.emplace(q);
            }
            cout << dsu.comps << '\n';
        }
    }
    return 0;
}
