#include<bits/stdc++.h>
using namespace std;

#define long long long
const int N = 405;
const long inf = 1e16 + 9;
long d[N][N];


struct bridge{
    int u, v, w;
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 1; i < N; i++){
        for(int j = 1; j < N; j++){
             d[i][j] = inf;
             if(i == j){
                 d[i][j] = 0;
             }
        }
    }
    int n, m;
    cin >> n >> m;
    vector<bridge> edges(m + 1);
    for(int i = 1; i <= m; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        d[u][v] = min(d[u][v], 1LL * w);
        d[v][u] = min(d[v][u], 1LL * w);
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    int q;
    cin >> q;
    while(q--){
        int k;
        cin >> k;
        vector<int> p(k); long cost = 0;
        for(int i = 0; i < k; i++){
            cin >> p[i];
            cost += edges[p[i]].w;
        }
        long ans = inf;
        for(int msk = 0; msk < (1 << k); msk++){
            vector<bridge> new_bridge;
            for(int i = 0; i < k; i++){
                if(msk >> i & 1){
                    new_bridge.push_back({edges[p[i]].v, edges[p[i]].u, edges[p[i]].w});
                }else{
                    new_bridge.push_back({edges[p[i]].u, edges[p[i]].v, edges[p[i]].w});
                }
            }
            vector<int> perm(k);
            iota(perm.begin(), perm.end(), 0);
            do{
                int node = 1; long sum = 0;
                for(int i = 0; i < k; i++){
                    sum += d[node][new_bridge[perm[i]].u];
                    node = new_bridge[perm[i]].v;
                }
                sum += d[node][n];
                ans = min(ans, sum + cost);
            }while(next_permutation(perm.begin(), perm.end()));
        }
        cout << ans << '\n';
    }
    return 0;
}
