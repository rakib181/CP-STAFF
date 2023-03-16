#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 105;
int dp[2][N];

int cal_1(int i, vector<int> &A){
    if(i < 2) return 0;
    if(dp[0][i] != -1)return dp[0][i];
    return dp[0][i] = max(cal_1(i - 1, A), cal_1(i - 2, A) + A[i]);
}
int cal_2(int i,vector<int> &A){
    if(i < 1) return 0;
    if(dp[1][i] != -1)return dp[1][i];
    return dp[1][i] = max(cal_2(i - 1, A), cal_2(i - 2, A) + A[i]);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(n == 1) {
        cout << a[1] << '\n';
    }else {
        memset(dp, -1, sizeof dp);
        dp[0][0] = 0, dp[0][1] = a[1];
        dp[1][0] = 0, dp[1][1] = a[1];
        cal_1(n, a);
        cal_2(n - 1, a);
        cout << max(dp[0][n], dp[1][n - 1]) << '\n';
    }
    return 0;
}
