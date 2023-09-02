#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 17;
int g[N][N];
ll dp[(1 << N) + 1];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            cin >> g[i][j];
        }
    }
    for(int i = 0; i < (1 << n); i++){
        int x = 0;
        for(int j = 0; j < n; j++){
            if(!((i >> j) & 1)){
                x = j;
                break;
            }
        }
        for(int j = 0; j < n; j++){
            if(!((i >> j) & 1) and j != x){
                int mask = i | (1 << x) | (1 << j);
                dp[mask] = max(dp[mask], dp[i] + g[x][j]);
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < (1 << n); i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
    return 0;
}
