#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int bin(int x, int y, int mod){
    int ans = 1;
    while(y){
        if(y & 1){
            ans = 1LL * ans * x % mod;
        }
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return ans;
}

int f(int a, int n, int mod){
    if(n == 0){
        return 0;
    }
    int ret = 0;
    if(n & 1){
        int c = 1LL * (1LL * a * f(a, n - 1, mod)) % mod;
        c += 1;
        c %= mod;
        ret = 1LL * (1LL * ret + c) % mod;
    }else{
        int c = 1LL * ((1LL + a) * f(1LL * (1LL * a * a) % mod, n / 2, mod)) % mod;
        ret = 1LL * (1LL * ret + c) % mod;
    }
    return ret;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n, a, m;
        cin >> n >> a >> m;
        cout << f(a, n, m) << ' ' << bin(a, n, m) << '\n';
    }
    return 0;
}
