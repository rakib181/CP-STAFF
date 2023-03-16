#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 9;
int dp[4][N];

int cal(int i, vector<int> &a, vector<int> &b, vector<int> &c, int type){
     if(i == 1){
         if(type == 1){
             return max(dp[2][i], dp[3][i]);
         }else if(type == 2){
             return max(dp[1][i], dp[3][i]);
         }else return max(dp[1][i], dp[2][i]);
     }
     if(dp[type][i] != -1){
         return dp[type][i];
     }
     int ans;
     if(type == 1) ans = a[i] + max(cal(i - 1, a, b, c, 2), cal(i - 1, a, b, c, 3));
     else if(type == 2)  ans = b[i] + max(cal(i - 1, a, b, c, 1), cal(i - 1, a, b, c, 3));
     else  ans = c[i] + max(cal(i - 1, a, b, c, 1), cal(i - 1, a, b, c, 2));
     return dp[type][i] = ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    memset(dp, -1, sizeof dp);
    dp[1][1] = a[1], dp[2][1] = b[1], dp[3][1] = c[1];
    cal(n, a, b, c, 1), cal(n, a, b, c, 2), cal(n, a, b, c, 3);
    cout << max({dp[1][n], dp[2][n], dp[3][n]}) << '\n';
    return 0;
}
