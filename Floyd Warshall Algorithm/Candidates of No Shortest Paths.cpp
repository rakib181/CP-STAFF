#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> d(n + 1, vector<int> (n + 1, inf));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j)d[i][j] = 0;
        }
    }
    int u[m + 1], v[m + 1], w[m + 1];
    for(int i = 1; i <= m; i++){
        cin >> u[i] >> v[i] >> w[i];
        d[u[i]][v[i]] = min(d[u[i]][v[i]], w[i]);
        d[v[i]][u[i]] = min(d[v[i]][u[i]], w[i]);
    }
    for(int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    int ans = m;
    for(int i = 1; i <= m; i++){
        bool possible = false;
        for(int j = 1; j <= n; j++){
             if(d[j][u[i]] + w[i] == d[j][v[i]])possible = true;
        }
        ans -= possible;
    }
    cout << ans << '\n';
    return 0;
}
