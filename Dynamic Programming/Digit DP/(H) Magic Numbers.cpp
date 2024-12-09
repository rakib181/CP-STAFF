#include <bits/stdc++.h>
using namespace std;
#define long long long

const int N = 2e3 + 9, mod = 1e9 + 7;
int n, d, m, dp[N][N][2];
string s;

int f(int i, int sum, int is_smaller){
    if(i == n){
        return sum == 0;
    }
    if(dp[i][sum][is_smaller] != -1)return dp[i][sum][is_smaller];
    int ans = 0;
    if(i & 1){
        if(is_smaller or (d <= (s[i] - '0'))) {
            ans += f(i + 1, (sum * 10 % m + d) % m, is_smaller | (d < (s[i] - '0')));
            ans %= mod;
        }
    }else{
        int dig = s[i] - '0';
        int last = (is_smaller ? 9 : dig);
        for(int x = (i == 0 ? 1 : 0); x <= last; x++){
            if(x == d)continue;
            ans += f(i + 1, (sum * 10 % m + x) % m, is_smaller | (x < dig));
            ans %= mod;
        }
    }
    return dp[i][sum][is_smaller] = ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof dp);
    cin >> m >> d;
    string l, r;
    cin >> l >> r;
    n = (int) r.size();
    s = r;
    int ans = f(0, 0, 0);
    memset(dp, -1, sizeof dp);
    n = (int) l.size();
    s = l;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            s[i] = '9';
        } else {
            s[i] = char((s[i] - '0') - 1 + '0');
            break;
        }
    }
    n = (int) s.size();
    ans -= f(0, 0, 0);
    ans %= mod;
    ans += mod;
    ans %= mod;
    cout << ans % mod;

    return 0;
}
