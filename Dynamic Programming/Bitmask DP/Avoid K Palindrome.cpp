#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1005, mod = 998244353;
int n, k, dp[N][N + 50];
string s;

int pal(int msk){
    int l = 0, r = k - 1;
    while(l <= r){
        if((msk >> l & 1) != (msk >> r & 1))return false;
        l += 1, r -= 1;
    }
    return true;
}

int get_mask(int msk, int i, int c){
    if(i >= k){
        return (msk >> 1) | (c * (1 << (k - 1)));
    }else{
        return msk | (c * (1 << i));
    }
}

int f(int i, int msk){
    if(i >= k and pal(msk))return 0;
    if(i == n){
        return 1;
    }
    if(dp[i][msk] != -1)return dp[i][msk];
    int ans = 0;
    if(s[i] != '?'){
         ans += f(i + 1, get_mask(msk, i, s[i] == 'A'));
         ans %= mod;
    }else{
       ans += f(i + 1, get_mask(msk, i, 1));
       ans %= mod;
       ans += f(i + 1, get_mask(msk, i, 0));
       ans %= mod;
    }
    return dp[i][msk] = ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k >> s;
    memset(dp, -1, sizeof dp);
    cout << f(0, 0);
    return 0;
}
