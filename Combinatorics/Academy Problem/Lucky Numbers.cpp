#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll power(ll x, ll y){
    ll ans = 1;
    while(y){
        if(y & 1) ans = ans * x;
        x *= x;
        y >>= 1;
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << power(2, n + 1) - 2;
    return 0;
}