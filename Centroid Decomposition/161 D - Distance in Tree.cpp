#include<bits/stdc++.h>
using namespace std;

#define long long long int

const int N = 5e4 + 9;
vector<int> g[N], sz(N), cnt(N);
vector<bool> vis(N);

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

int k, mx_distance;
long ans = 0;

void cal(int u, int p, int d, bool is_cal){
    if(d > k)return;
    if(is_cal){
        ans += cnt[k - d];
    }else{
        cnt[d]++;
    }
    mx_distance = max(mx_distance, d);
    for(auto v : g[u]){
        if(!vis[v] and v != p){
            cal(v, u, d + 1, is_cal);
        }
    }
}

void solve(int u, int p){
    size(u, 0);
    int c = find_centroid(u, 0, sz[u]);
    vis[c] = true;
    cnt[0] = 1;
    mx_distance = 0;
    for(auto v : g[c]){
        if(!vis[v]){
            cal(v, c, 1, true);
            cal(v, c, 1, false);
        }
    }
    for(int i = 0; i <= mx_distance; i++)cnt[i] = 0;
    for(auto v : g[c]){
        if(!vis[v]){
            solve(v, u);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n >> k;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    solve(1, 0);
    cout << ans << '\n';
    return 0;
}
