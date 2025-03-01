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
const int inf = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 2e5 + 9, M = 25;
vector<int> g[N], d(N);
vector<vector<int>> p(N, vector<int> (M));

void dfs(int u, int par){
    p[u][0] = par;
    for(int i = 1; i < M; i++){
        p[u][i] = p[p[u][i - 1]][i - 1];
    }
    for(auto v : g[u]){
        if(v == par)continue;
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}

int lca(int a, int b){
    int x = d[a], y = d[b];
    if(x < y)swap(a, b);
    for(int i = M - 1; i >= 0; i--){
        int v = p[a][i];
        if(d[v] >= d[b]){
            a = v;
        }
    }
    if(a == b)return a;
    for(int i = M - 1; i >= 0; i--){
        int u = p[a][i], v = p[b][i];
        if(u != v){
            a = u, b = v;
        }
    }
    return p[a][0];
}

int distance(int a, int b){
    int lc = lca(a, b);
    return d[a] + d[b] - 2 * d[lc];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int u = 2; u <= n; u++){
        int v;
        cin >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1, 0);
    int u = 1, v = 2, ans = 1;
    for(int i = 2; i <= n; i++){
        int x = distance(u, i), y = distance(v, i);
        if(x > ans){
            v = i;
            ans = x;
        }
        if(y > ans){
            u = i;
            ans = y;
        }
        cout << ans << ' ';
    }
    cout << '\n';
    return 0;
}
