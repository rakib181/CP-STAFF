#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 9;
int dp[4][N];

int cal(int i, vector<int> &a, vector<int> &b, vector<int> &c, int type){
    if(i == 1){
        if(type == 1){
            return a[1];
        }else if(type == 2){
            return b[1];
        }else return c[1];
    }
    if(dp[type][i] != -1){
        return dp[type][i];
    }
    int ans;
    if(type == 1) ans = a[i] + min(cal(i - 1, a, b, c, 2), cal(i - 1, a, b, c, 3));
    else if(type == 2)  ans = b[i] + min(cal(i - 1, a, b, c, 1), cal(i - 1, a, b, c, 3));
    else  ans = c[i] + min(cal(i - 1, a, b, c, 1), cal(i - 1, a, b, c, 2));
    return dp[type][i] = ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--) {
        cout << "Case " << cs++ << ": ";
        int n;
        cin >> n;
        vector<int> a(n + 1), b(n + 1), c(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i] >> c[i];
        }
        if(n == 2){
            cout << min({a[1], b[1], c[1]}) + min({a[2], b[2], c[2]});
            continue;
        }
        memset(dp, -1, sizeof dp);
        dp[1][1] = a[1], dp[2][1] = b[1], dp[3][1] = c[1];
        cal(n, a, b, c, 1), cal(n, a, b, c, 2), cal(n, a, b, c, 3);
        cout << min({dp[1][n], dp[2][n], dp[3][n]}) << '\n';
    }
    return 0;
}
