#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll power(ll x, int y){
    ll ans = 1;
    while(y){
        if(y & 1) ans *= x;
        x *= x;
        y >>= 1;
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while(t--){
       int n, one = 0, zero = 0;
       cin >> n;
       for(int i = 1; i <= n; i++){
           int x;
           cin >> x;
           one += (x == 1);
           zero += (x == 0);
       }
       cout << 1LL * one * power(2, zero) << '\n';
    }
    return 0;
}