#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9, mod = 1e9 + 7;
int f[N];

int power(int x, int y){
    int ans = 1;
    while(y){
        if(y & 1) ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return ans;
}

int inv(int x){
    return power(x, mod - 2);
}

void cal(){
    f[0] = 1;
    for(int i = 1; i < N; i++){
        f[i] = 1LL * f[i - 1] * i % mod;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cal();
    int t;
    cin >> t;
    while(t--){
       int n;
       cin >> n;
       cout << 1LL * f[2 * n] * inv(2) % mod << '\n';
    }
    return 0;
}