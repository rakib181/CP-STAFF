#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100;
int n; ll dp[N];

ll f(int x){
    if(x > n)return 0;
    if(x == n)return 1;
    if(dp[x] != -1)return dp[x];
    return dp[x] = f(x + 1) + f(x + 2);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    while(cin >> n and n){
        for(int i = 0; i <= n; i++){
            dp[i] = -1;
        }
        cout << f(0) << '\n';
    }
    return 0;
}