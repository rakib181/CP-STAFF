#include <bits/stdc++.h>
using namespace std;

const long long INF = 1 << 62;

class edge{
public:
    long long u, v, wt;
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<edge> g(m + 1);
    for(int i = 0; i < m; i++){
       cin >> g[i].u >> g[i].v >> g[i].wt;
    }
    long long dist[n + 1], par[n + 1];

    for(int i = 1; i <= n; i++){
        dist[i] = INF;
        par[i] = 0;
    }
    dist[1] = 0; int f;
    for(int i = 1; i < n + 1; i++){
        f = 0;
        for(auto x : g){
            if(dist[x.v] > dist[x.u] + x.wt){
                dist[x.v] = dist[x.u] + x.wt;
                par[x.v] = x.u;
                f = x.v;
            }
        }
    }
    if(!f) cout << "NO" << '\n';
    else{
        cout << "YES" << '\n';
        for(int i = 1; i < n + 1; i++){
            f = par[f];
        }
        vector<long long> path;
        for(long long cur = f;; cur = par[cur]){
            path.push_back(cur);
            if(cur == f and path.size() > 1)break;
        }
        reverse(path.begin(), path.end());
        for(auto x : path){
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}
