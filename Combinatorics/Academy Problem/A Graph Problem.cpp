#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 80;
ll dp[N];

ll f(int n){
    if(n < 0)return 0;
    if(n == 0 or n == 1)return 1;
    if(n == 2)return 2;
    if(dp[n] != -1)return dp[n];
    return dp[n] = f(n - 2) + f(n - 3);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    while(cin >> n){
        for(int i = 0; i <= n; i++){
            dp[i] = -1;
        }
        cout << f(n) << '\n';
    }
    return 0;
}