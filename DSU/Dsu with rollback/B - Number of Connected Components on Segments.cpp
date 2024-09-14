#include<bits/stdc++.h>
using namespace std;

#define long long long int

const int K = 500;

struct save{
    int u, rnk_u, v, rnk_v;
    save(int _u, int _rnk_u, int _v, int _rnk_v) : u(_u), rnk_u(_rnk_u), v(_v), rnk_v(_rnk_v) {};
};

struct dsu{
   vector<int> p, rank, point;
   stack<save> snapshot;
   int components;
   void init(int n){
       this -> components = n;
       this -> p.resize(n);
       this -> rank.resize(n);
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
       if(u == v)return false;
       if(rank[u] > rank[v])swap(u, v);
       snapshot.emplace(u, rank[u], v, rank[v]);
       components--;
       p[u] = v;
       if(rank[u] == rank[v]){
           rank[v]++;
       }
       return true;
   }

   void rollback(){
       if(point.empty())return;
       while(snapshot.size() > point.back()){
           auto x = snapshot.top();
           snapshot.pop();
           components++;
           p[x.u] = x.u, p[x.v] = x.v;
           rank[x.u] = x.rnk_u, rank[x.v] = x.rnk_v;
       }
       point.pop_back();
   }
   void add_point(){
       point.emplace_back(snapshot.size());
   }
}dsu;

struct query{
    int l, r, id;
    bool operator < (query &other) const{
        return this -> r < other.r;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for(int i = 0; i < m; i++){
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--, edges[i].second--;
    }
    int cnt = (m - 1) / K + 1;
    vector<query> block[cnt];
    dsu.init(n);
    int q;
    cin >> q;
    vector<int> ans(q);
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        l--, r--;
        if(l / K == r / K){
             dsu.add_point();
             for(int j = l; j <= r; j++){
                 dsu.unite(edges[j].first, edges[j].second);
             }
             ans[i] = dsu.components;
             dsu.rollback();
        }else{
            block[l / K].push_back({l, r, i});
        }
    }
    for(int i = 0; i < cnt; i++){
        int cr = K * (i + 1), cl = cr;
        sort(block[i].begin(), block[i].end());
        dsu.add_point();
        for(auto [l, r, id] : block[i]){
            while(cr <= r){
                dsu.unite(edges[cr].first, edges[cr].second);
                cr++;
            }
            dsu.add_point();
            for(int j = l; j <= cl; j++){
                dsu.unite(edges[j].first, edges[j].second);
            }
            ans[id] = dsu.components;
            dsu.rollback();
        }
        dsu.rollback();
    }
    for(int i = 0; i < q; i++){
        cout << ans[i] << '\n';
    }
    return 0;
}
