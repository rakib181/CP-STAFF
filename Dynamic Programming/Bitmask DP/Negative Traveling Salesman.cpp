#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e16 + 9;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> d(n, vector<ll> (n, inf));
    for(int i = 0; i < n; i++){
        d[i][i] = 0;
    }
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u -= 1, v -= 1;
        d[u][v] = min(d[u][v], 1LL * w);
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(d[i][k] == inf or d[k][j] == inf)continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    vector<vector<ll>> ans((1 << n), vector<ll> (n, inf));
    for(int i = 0; i < n; i++){
        ans[(1 << i)][i] = 0;
    }
    for(int msk = 0; msk < (1 << n); msk++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if((msk >> j) & 1)continue;
                if(ans[msk][i] == inf or d[i][j] == inf)continue;
                ans[(msk | (1 << j))][j] = min(ans[(msk | (1 << j))][j], ans[msk][i] + d[i][j]);
            }
        }
    }
    ll f = inf;
    for(int i = 0; i < n; i++){
        f = min(f, ans[(1 << n) - 1][i]);
    }
    if(f == inf){
        cout << "No\n";
    }else{
        cout << f << '\n';
    }
    return 0;
}
