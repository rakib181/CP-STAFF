#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 55, NX = 1005, MOD = 100000007;
int dp[N][NX]; vector<int> a, c; int n, k;

int coin_change(int i, int val){
    if(val == 0)return 1;
    if(i > n) return 0;
    if(dp[i][val] != -1)return dp[i][val];
    dp[i][val] = 0;
    for(int j = 0; j <= c[i]; j++){
        if(val - (j * a[i]) >= 0){
            dp[i][val] += coin_change(i + 1, val - (j * a[i]));
            dp[i][val] %= MOD;
        }
    }
    return dp[i][val];
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--) {
        cout << "Case " << cs++ << ": ";
        cin >> n >> k;
        a.resize(n + 1), c.resize(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> c[i];
        }
        memset(dp, -1, sizeof dp);
        cout << coin_change(1, k) << '\n';
    }
    return 0;
}
