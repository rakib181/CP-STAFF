#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    int ar[n];
    for(int i = 0; i < n; i++)cin >> ar[i];
    int row = log2(n);
    int dp[row][n];
    for(int i = 0; i < n; i++)dp[0][i] = ar[i];
    for(int i = 1; i <= row; i++){
        for(int j = 0; j + (1 << (i - 1)) <= n; j++){
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
        }
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        int k = log2(r - l + 1);
        cout << min(dp[k][l], dp[k][r - (1 << k) + 1]) << '\n';
    }
    return 0;
}
