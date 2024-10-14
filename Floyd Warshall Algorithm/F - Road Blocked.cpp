#include<bits/stdc++.h>
using namespace std;
#define long long long
const long inf = 1e18 + 9;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long>> d(n + 1, vector<long> (n + 1, inf));
    for(int i = 1; i <= n; i++){
        d[i][i] = 0;
    }
    vector<array<int, 3>> edges(m + 1);
    for(int i = 1; i <= m; i++){
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    vector<int> x(q + 1), y(q + 1), op(q + 1), del(m + 1), v(q + 1);
    for(int i = 1; i <= q; i++){
        cin >> op[i];
        if(op[i] == 1){
            cin >> v[i];
            del[v[i]] = 1;
        }else{
            cin >> x[i] >> y[i];
        }
    }
    for(int i = 1; i <= m; i++){
        if(del[i])continue;
        d[edges[i][0]][edges[i][1]] = min(d[edges[i][0]][edges[i][1]], 1LL * edges[i][2]);
        d[edges[i][1]][edges[i][0]] = min(d[edges[i][1]][edges[i][0]], 1LL * edges[i][2]);
    }
    for(int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    vector<long> ans(q + 1);
    for(int Q = q; Q >= 1; Q--){
        if(op[Q] == 1){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    d[i][j] = min(d[i][j], d[i][edges[v[Q]][0]] + d[edges[v[Q]][1]][j] + edges[v[Q]][2]);
                    d[i][j] = min(d[i][j], d[i][edges[v[Q]][1]] + d[edges[v[Q]][0]][j] + edges[v[Q]][2]);
                }
            }
        }else{
            ans[Q] = d[x[Q]][y[Q]];
        }
    }
    for(int i = 1; i <= q; i++){
        if(op[i] == 2){
            cout << (ans[i] == inf ? -1 : ans[i]) << '\n';
        }
    }
    return 0;
}
