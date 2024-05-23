#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
vector<int> g[N];
vector<int> d(N), c(N);
vector<ll> sz(N);
ll sum = 0;

void dfs(int u, int p){
    sz[u] = c[u];
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
            if(sz[v] > sum / 2){
                centroid = false;
            }
        }
    }
    if(sum - sz[u] > sum / 2){
        centroid = false;
    }
    return centroid ? u : -1;
}

void dist(int u, int p){
    for(auto v : g[u]){
        if(v != p){
            d[v] = d[u] + 1;
            dist(v, u);
        }
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
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    sum = accumulate(c.begin() + 1, c.begin() + n + 1, 0LL);
    dfs(1, 0);
    int centroid = find_centroid(1, 0);
    dist(centroid, 0);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += 1LL * d[i] * c[i];
    }
    cout << ans << '\n';
    return 0;
}
