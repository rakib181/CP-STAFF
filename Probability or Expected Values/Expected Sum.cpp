#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 998244353;

int modInv(int a, int b){
    int ans = 1;
    while (b){
        if(b & 1)ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        int a, b, n, k;
        cin >> a >> b;
        n = (a + b);
        k = (n + 1) / 2;
        int ans = (k * a) % mod * modInv(n, mod - 2);
        cout << ans % mod << '\n';
    }
    return 0;
}
