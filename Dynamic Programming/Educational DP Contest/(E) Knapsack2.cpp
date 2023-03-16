#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int NX = 105, N = 1e5 + 1, inf = 1e13;
bool dp[NX][N]; int mW[NX][N], v[NX], w[NX];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, W;
    cin >> n >> W;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < N; j++){
            dp[i][j] = false;
            mW[i][j] = inf;
        }
    }
    dp[0][0] = true; mW[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int val = 0; val < N; val++){
            if(dp[i - 1][val]){
                dp[i][val] = true;
                mW[i][val] = min(mW[i][val], mW[i - 1][val]);
            }
            if(val - v[i] >= 0 and dp[i - 1][val - v[i]] and mW[i - 1][val - v[i]] + w[i] <= W){
                dp[i][val] = true;
                mW[i][val] = min(mW[i][val], mW[i - 1][val - v[i]] + w[i]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(dp[n][i]){
            ans = i;
        }
    }
    cout << ans << '\n';
    return 0;
}
