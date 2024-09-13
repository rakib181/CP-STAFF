#include<bits/stdc++.h>
using namespace std;
#define long long long int

struct dsu{
    vector<int> p, sz, len;
    int components{};
    void init(int n){
        this -> components = n;
        this -> p.resize(n);
        this -> sz.resize(n);
        this -> len.resize(n);
        for(int i = 0; i < n; ++i){
            p[i] = i;
            sz[i] = 1;
            len[i] = 0;
        }
    }

    pair<int, int> find(int u){
        if(u == p[u])return {u, 0};
        pair<int, int> val = find(p[u]);
        p[u] = val.first;
        len[u] = (len[u] + val.second) % 2;
        return {p[u], len[u]};
    }

    bool unite(int u, int v){
        pair<int, int> val1 = find(u), val2 = find(v);
        if(val1.first == val2.first)return val1.second == val2.second;
        if(sz[val1.first] > sz[val2.first]){
            swap(val1, val2);
        }
        components--;
        p[val1.first] = val2.first;
        sz[val2.first] += sz[val1.first];
        len[val1.first] = (val1.second + val2.second + 1) % 2;
        return false;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, shift = 0;
    cin >> n >> m;
    dsu dsu;
    dsu.init(n);
    while(m--){
        int type;
        cin >> type;
        if(type == 0){
            int u, v;
            cin >> u >> v;
            u--, v--;
            u = (u + shift) % n, v = (v + shift) % n;
            dsu.unite(u, v);
        }else{
            int u, v;
            cin >> u >> v;
            u--, v--;
            u = (u + shift) % n, v = (v + shift) % n;
            if(dsu.unite(u, v)){
                cout << "YES\n";
                shift = (shift + 1) % n;
            }else{
                cout << "NO\n";
            }
        }
    }
    return 0;
}
