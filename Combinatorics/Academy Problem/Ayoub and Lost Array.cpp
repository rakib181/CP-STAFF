#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9, mod = 1e9 + 7;
int get(int n, int k){
    if(k == 0){
        return n / 3;
    }else if(k == 1){
        return n / 3 + (n % 3 >= 1);
    }else{
        return n / 3 + (n % 3 >= 2);
    }
}
int n, l, r, dp[N][3];

int f(int i, int sum){
    if(i == n + 1){
        return sum == 0;
    }
    int &ans = dp[i][sum];
    if(ans != -1)return ans;
    ans = 0;
    for(int k = 0; k < 3; k++){
        int cnt = get(r, k) - get(l - 1, k);
        ans = 1LL * (ans + 1LL * f(i + 1, (sum + k) % 3) * cnt % mod) % mod;
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> l >> r;
    memset(dp, -1, sizeof dp);
    cout << f(1, 0);
    return 0;
}