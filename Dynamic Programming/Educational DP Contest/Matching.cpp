#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 22, mod = 1e9 + 7;
int n, g[N][N], dp[N][(1 << N)];

int f(int id, int msk){
    if(id == n)return 1;
    if(dp[id][msk] != -1)return dp[id][msk];
    int ans = 0;
    for(int i = 0; i < n; i++){
        if((msk >> i) & 1)continue;
        if(!g[id][i])continue;
        ans += f(id + 1, msk | (1 << i));
        ans %= mod;
    }
    return dp[id][msk] = ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <  n; j++){
            cin >> g[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    cout << f(0, 0) << '\n';
    return 0;
}
