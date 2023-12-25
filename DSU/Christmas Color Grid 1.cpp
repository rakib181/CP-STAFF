#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;

int bin(int x, int y){
    int ans = 1;
    while(y){
        if(y & 1) ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return ans;
}

struct dsu{
    vector<int> p, sz;
    void reset(){
        p.assign(2e6, 0);
        sz.assign(2e6, 1);
        iota(p.begin(), p.end(), 0);
    }
    int find(int u){
        if(u == p[u]){
            return u;
        }
        return p[u] = find(p[u]);
    }

    void unite(int u, int v){
        u = find(u), v = find(v);
        if(u == v)return;
        if(sz[u] > sz[v])swap(u, v);
        p[v] = u;
        sz[u] += sz[v];
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, red = 0;
    cin >> n >> m;
    vector<vector<char>> g(n + 1, vector<char> (m + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> g[i][j];
            red += g[i][j] == '.';
        }
    }
    dsu ds;
    ds.reset();
    vector<int> c;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(g[i][j] == '#'){
                if(i - 1 >= 1 and g[i - 1][j] == '#'){
                    int x = i * m + j, y = (i - 1) * m + j;
                    ds.unite(x, y);
                }
                if(i + 1 <= n and g[i + 1][j] == '#'){
                    int x = i * m + j, y = (i + 1) * m + j;
                    ds.unite(x, y);
                }
                if(j - 1 >= 1 and g[i][j - 1] == '#'){
                    int x = i * m + j, y = i * m + (j - 1);
                    ds.unite(x, y);
                }
                if(j + 1 <= m and g[i][j + 1] == '#'){
                    int x = i * m + j, y = i * m + (j + 1);
                    ds.unite(x, y);
                }
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int x = i * m + j;
            if(g[i][j] == '#' and ds.find(x) == x){
                cnt += 1;
            }
        }
    }
    int tot = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            set<int> se;
            if(g[i][j] == '.'){
                if(i - 1 >= 1 and g[i - 1][j] == '#'){
                    int y = (i - 1) * m + j;
                    se.insert(ds.find(y));
                }
                if(i + 1 <= n and g[i + 1][j] == '#'){
                    int y = (i + 1) * m + j;
                    se.insert(ds.find(y));
                }
                if(j - 1 >= 1 and g[i][j - 1] == '#'){
                    int y = i * m + (j - 1);
                    se.insert(ds.find(y));
                }
                if(j + 1 <= m and g[i][j + 1] == '#'){
                    int y = i * m + (j + 1);
                    se.insert(ds.find(y));
                }
                tot += (cnt - ((int) se.size() - 1));
                tot %= mod;
            }
        }
    }
    cout << 1LL * tot * bin(red, mod - 2) % mod << '\n';
    return 0;
}
