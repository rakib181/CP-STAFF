#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int n;
vector<int> g[N];
vector<ll> sz(N);

void dfs(int u, int p){
    sz[u] = 1;
    for(auto v : g[u]){
        if(v != p){
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}

int find_centroid(int u, int p){
    bool centroid = true;
    for(auto v : g[u]){
        if(v != p){
            int res = find_centroid(v, u);
            if(res != -1){
                return res;
            }
            if(sz[v] > n / 2){
                centroid = false;
            }
        }
    }
    if(n - sz[u] > n / 2){
        centroid = false;
    }
    return centroid ? u : -1;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1, 0);
    int centroid = find_centroid(1, 0);
    cout << centroid << '\n';
    return 0;
}
