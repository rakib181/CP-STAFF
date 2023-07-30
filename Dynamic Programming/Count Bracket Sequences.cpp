#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e3 + 9, MOD = 998244353;
int n, dp[N][N];
string s;

int f(int i, int take){
    if(i == n)return take == 0;
    int &ans = dp[i][take];
    if(ans != -1)return ans;
    ans = 0;
    if(s[i] == '('){
       ans += f(i + 1, take + 1);
       ans %= MOD;
    }else if(s[i] == ')'){
        ans += (take <= 0 ? 0 : f(i + 1, take - 1));
    }else{
        ans += f(i + 1, take + 1);
        ans %= MOD;
        ans += (take <= 0 ? 0 : f(i + 1, take - 1));
        ans %= MOD;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof dp);
    cin >> s;
    n = (int) s.size();
    cout << f(0, 0) << '\n';
    return 0;
}
