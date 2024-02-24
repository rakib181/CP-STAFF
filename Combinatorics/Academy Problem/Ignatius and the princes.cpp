#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 150;
int dp[N][N], n;

int f(int lst, int sum){
    if(sum == n)return 1;
    if(dp[lst][sum] != -1)return dp[lst][sum];
    int ans = 0;
    for(int i = lst; i <= n; i++){
       if(sum + i <= n)  ans += f(i, sum + i);
    }
    return dp[lst][sum] = ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    while(cin >> n){
        memset(dp, -1, sizeof dp);
        cout << f(1, 0) << '\n';
    }
    return 0;
}