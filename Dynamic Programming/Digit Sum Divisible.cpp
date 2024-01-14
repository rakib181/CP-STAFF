#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 18, MX = 220;
ll dp[N][MX][MX][2];
string s;
int n, summation;

ll digdp(int i, int mod, int sum, int is_smaller){
    if(i == n){
        return (mod == 0 and sum == summation);
    }
    if(sum > summation)return 0;
    if(dp[i][mod][sum][is_smaller] != -1)return dp[i][mod][sum][is_smaller];
    ll ans = 0;
    for(int d = 0; d <= (!is_smaller ? (s[i] - '0') : 9); d++){
        ans += digdp(i + 1, (mod * 10 + d) % summation, sum + d, is_smaller | (d < (s[i] - '0')));
    }
    return dp[i][mod][sum][is_smaller] = ans;
}

ll ans = 0;
void cal(int sum){
    summation = sum;
    memset(dp, -1, sizeof dp);
    ans += digdp(0, 0, 0, 0);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    n = (int) s.size();
    for(int i = 1; i <= 129; i++){
        cal(i);
    }
    cout << ans << '\n';
    return 0;
}
