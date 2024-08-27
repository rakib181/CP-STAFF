#include<bits/stdc++.h>
using namespace std;

#define long long long int

const int N = 2e5 + 5;
vector<int> g[N], sz(N);
vector<bool> vis(N);

struct BIT {
    int n{};
    vector<int> t;
    void init(int _n){
        this -> n = _n + 2;
        this -> t.assign(n, 0);
    }
    void add(int i, int v) {
        i++;
        while (i < n) {
            t[i] += v;
            i += (i & -i);
        }
    }
    int query(int i) {
        i++;
        int sum = 0;
        while (i) {
            sum += t[i];
            i -= (i & -i);
        }
        return sum;
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
}fn;

void size(int u, int p){
    sz[u] = 1;
    for(auto v : g[u]){
        if(vis[v] or v == p)continue;
        size(v, u);
        sz[u] += sz[v];
    }
}

int find_centroid(int u, int p, int n){
     for(auto v : g[u]){
         if(vis[v] or v == p or sz[v] * 2 < n){
             continue;
         }
         return find_centroid(v, u, n);
     }
    return u;
}

int k1{}, k2{}, mx_distance{};
long ans = 0;

void cal(int u, int p, int d, bool is_cal){
    if(d > k2)return;
    if(is_cal){
        ans += fn.query(max(0, k1 - d), k2 - d);
    }else{
        fn.add(d, +1);
    }
    mx_distance = max(mx_distance, d);
    for(auto v : g[u]){
        if(!vis[v] and v != p){
            cal(v, u, d + 1, is_cal);
        }
    }
}

void solve(int u){
    size(u, 0);
    int c = find_centroid(u, 0, sz[u]);
    vis[c] = true;

    mx_distance = 0;
    for(auto v : g[c]){
        if(!vis[v]){
            cal(v, c, 1, true);
            cal(v, c, 1, false);
        }
    }
    for(int i = 1; i <= mx_distance; i++){
        fn.add(i, -fn.query(i, i));
    }
    for(auto v : g[c]){
        if(!vis[v]){
            solve(v);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n >> k1 >> k2;
    if(k2 - k1 == n - 1){
        cout << 1LL * n * (n - 1) / 2 << '\n';
        return 0;
    }
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    fn.init(n);
    fn.add(0, +1);
    solve(1);
    cout << ans << '\n';
    return 0;
}
