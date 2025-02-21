#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// @author  heisenberg

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

#define long long long
typedef tree<pair<long, long>, null_type, greater<>, rb_tree_tag, tree_order_statistics_node_update> o_set;
const int N = 3e5 + 9, K = 25;

vector<int> g[N], depth(N);
vector<vector<int>> p(N, vector<int> (K));

void dfs(int u, int par){
    p[u][0] = par;
    for(int i = 1; i < K; i++){
        p[u][i] = p[p[u][i - 1]][i - 1];
    }
    for(int i = 0; i < (int) g[u].size(); i++){
        int v = g[u][i];
        if(v == par)continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int lca(int a, int b){
    int x = depth[a], y = depth[b];
    if(x < y)swap(a, b);
    for(int i = K - 1; i >= 0; i--){
        int v = p[a][i];
        if(depth[v] >= depth[b]){
            a = v;
        }
    }
    if(a == b)return a;
    for(int i = K - 1; i >= 0; i--){
        int u = p[a][i], v = p[b][i];
        if(u != v){
            a = u, b = v;
        }
    }
    return p[a][0];
}
int n, x, y;
vector<int> vis(N, 0);


int f(int u){
    vis[u] = true;
    int ans = 1;
    for(auto v : g[u]){
        if(vis[v])continue;
        ans += f(v);
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x >> y;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1, 0);
    long ans = 1LL * n * (n - 1);
    int lc = lca(x, y);
    int _x = x;
    while (_x != lc){
        vis[_x] = 1;
        _x = p[_x][0];
    }
    int _y = y;
    while (_y != lc){
        vis[_y] = 1;
        _y = p[_y][0];
    }
    vis[lc] = 1;
    int s1 = f(x);
    int s2 = f(y);
    ans -= 1LL * s1 * s2;
    cout << ans;
    return 0;
}
