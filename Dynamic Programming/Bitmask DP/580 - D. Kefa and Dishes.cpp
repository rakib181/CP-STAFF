#include<bits/stdc++.h>
using namespace std;

#define long long long int
const int N = (1 << 20);
int n, m, k, a[20], c[20][20];
long dp[N][20];

long f(int msk, int prev){
    if(__builtin_popcount(msk) == m)return 0;
    if(dp[msk][prev] != -1)return dp[msk][prev];
    long ans = 0;
    for(int i = 0; i < n; i++){
        if(!(msk >> i & 1)){
            ans = max(ans, f(msk | (1 << i), i) + a[i] + c[prev][i]);
        }
    }
    return dp[msk][prev] = ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= k; i++){
        int x, y, w;
        cin >> x >> y >> w;
        x--, y--;
        c[x][y] = w;
    }
    long ans = 0;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++){
        ans = max(ans, a[i] + f(1 << i, i));
    }
    cout << ans;
    return 0;
}

//Iterative
#include<bits/stdc++.h>
using namespace std;

#define long long long int
const int N = (1 << 20);
int n, m, k, a[20], c[20][20];
long dp[N][20];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= k; i++){
        int x, y, w;
        cin >> x >> y >> w;
        x--, y--;
        c[x][y] = w;
    }
    long ans = 0;
    for(int i = 0; i < n; i++){
        dp[1 << i][i] = a[i];
    }
    for(int msk = 0; msk < (1 << n); msk++){
         for(int i = 0; i < n; i++){
             if(msk >> i & 1){
                 for(int j = 0; j < n; j++){
                     if(!(msk >> j & 1)){
                         dp[msk | (1 << j)][j] = max(dp[msk | (1 << j)][j], a[j] + c[i][j] + dp[msk][i]);
                     }
                 }
             }
         }
    }
    for(int msk = 0; msk < (1 << n); msk++){
        if(__builtin_popcount(msk) == m){
           for(int i = 0; i < n; i++){
               ans = max(ans, dp[msk][i]);
           }
        }
    }
    cout << ans << '\n';
    return 0;
}
