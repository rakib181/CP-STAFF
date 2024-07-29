#include<bits/stdc++.h>
using namespace std;
#define long long long int

const int N = 1e5 + 9;
vector<int> g[N], dead(N), sz(N);
vector<char> res(N);

void size(int u, int p){
    sz[u] = 1;
    for(auto v : g[u]){
        if(dead[v] or v == p)continue;
        size(v, u);
        sz[u] += sz[v];
    }
}

int find_centroid(int u, int n, int p){
    bool centroid = true;
    for(auto v : g[u]){
        if(dead[v] or v == p) {
            continue;
        }
        int result = find_centroid(v, n, u);
        if(result != -1){
            return result;
        }
        if(sz[v] * 2 > n){
            centroid = false;
        }
    }
    if((n - sz[u]) * 2 > n){
        centroid = false;
    }
    return (centroid ? u : -1);
}

void dfs(int u, char c){
    size(u, 0);
    int cent = find_centroid(u, sz[u], 0);
    dead[cent] = 1;
    res[cent] = c;
    for(auto v : g[cent]){
        if(dead[v])continue;
        dfs(v, c + 1);
    }
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1, 'A');
    for(int i = 1; i <= n; i++){
        cout << res[i] << " \n"[i == n];
    }
    return 0;
}
