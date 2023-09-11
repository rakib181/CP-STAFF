#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5005;
int n;
ll dp[N];
string s;

ll f(int i){
    if(i == n)return 1;
    if(s[i] == '0')return 0;
    if(dp[i] != -1)return dp[i];
    ll ans = f(i + 1);
    if(i + 1 < n and s[i] == '1'){
        ans += f(i + 2);
    }
    if(i + 1 < n and s[i] == '2' and s[i + 1] <= '6'){
        ans += f(i + 2);
    }
    return dp[i] = ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin >> s and s[0] != '0'){
        n = (int) s.size();
        for(int i = 0; i <= n; i++){
            dp[i] = -1;
        }
        cout << f(0) << '\n';
    }
    return 0;
}
