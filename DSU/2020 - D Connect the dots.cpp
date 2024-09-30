#include<bits/stdc++.h>
using namespace std;

#define long long long int

class dsu{
public:
    vector<int> p, sz;
    int components = {};
    void init(int n){
        components = n - 1;
        p.assign(n, 0);
        sz.assign(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    int find(int v){
        if(p[v] == v)return v;
        return p[v] = find(p[v]);
    }

    void unite(int u, int v){
        u = find(u), v = find(v);
        if(u == v)return;
        if(sz[u] > sz[v]){
            swap(u, v);
        }
        components--;
        p[v] = u;
        sz[u] += sz[v];
    }
};

const int D = 12;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        dsu dsu;
        dsu.init(n + 1);
        vector<pair<int, int>> id[D][D];
        for(int i = 1; i <= m; i++){
            int x, d, k;
            cin >> x >> d >> k;
            id[d][x % d + 1].emplace_back(x, x + d * k);
        }
        for(int d = 1; d < D - 1; d++){
            for(int mod = 1; mod <= D - 1; mod++){
                auto &range = id[d][mod];
                sort(range.begin(), range.end());
                vector<pair<int, int>> st;
                for(auto [l, r] : range){
                    if(!st.empty() and l <= st.back().second){
                        st.back().second = max(st.back().second, r);
                    }else{
                        st.emplace_back(l, r);
                    }
                }
                for(auto [l, r] : st){
                    for(int v = l; v <= r; v += d){
                        dsu.unite(l, v);
                    }
                }
            }
        }
        cout << dsu.components << '\n';
    }
    return 0;
}
