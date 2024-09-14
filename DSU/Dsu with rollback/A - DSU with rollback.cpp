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
   int components{};
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


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    dsu.init(n);
    for(int i = 0; i < q; i++){
        string s;
        cin >> s;
        if(s[0] == 'p'){
            dsu.add_point();
        }else if(s[0] == 'r'){
            dsu.rollback();
            cout << dsu.components << '\n';
        }else{
            int u, v;
            cin >> u >> v;
            u--, v--;
            dsu.unite(u, v);
            cout << dsu.components << '\n';
        }
    }
    return 0;
}
