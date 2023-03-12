#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e3 + 9; int n, m;
int dp[N][N][2], a[N];

int sub_sum(int i, int sum, bool inc){
    if(i == n + 1){
        return sum == 0 and inc;
    }
    if(dp[i][sum][inc] != -1)return dp[i][sum][inc];
    dp[i][sum][inc] = sub_sum(i + 1, sum, inc);
    dp[i][sum][inc] |= sub_sum(i + 1, (sum + a[i]) % m, true);
    return dp[i][sum][inc];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] %= m;
    }
    if(n >= m)cout << "YES" << '\n';
    else{
        memset(dp, -1, sizeof dp);
        if(sub_sum(1, 0, false)){
            cout << "YES" << '\n';
        }else cout << "NO" << '\n';
    }
    return 0;
}
