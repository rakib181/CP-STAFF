#include<bits/stdc++.h>
using namespace std;
using ll = long long;

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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        int n;
        cin >> n;
        vector<int> x(n + 1), y(n + 1);
        vector<array<int, 3>> a;
        for(int i = 1; i <= n; i++){
            cin >> x[i] >> y[i];
        }
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                if(x[i] == x[j] or y[i] == y[j]){
                    a.push_back({((abs((x[i] - x[j]) + (y[i] - y[j])) + 1) / 2), i, j});
                }else{
                    a.push_back({max(abs(x[i] - x[j]), abs(y[i] - y[j])), i, j});
                }
            }
        }
        if(n == 1){
            cout << "0\n";
            continue;
        }
        dsu dsu;
        dsu.init(n + 1);
        sort(a.begin(), a.end());
        for(auto [c, u, v] : a){
            if(dsu.find(u) != dsu.find(v)){
                dsu.unite(u, v);
            }
            if(dsu.components == 1){
                cout << c << '\n';
                break;
            }
        }
    }
    return 0;
}
