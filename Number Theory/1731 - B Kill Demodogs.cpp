#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 1e9 + 7;

int modInv(int a, int b){
    int ans = 1;
    while (b){
        if(b & 1)ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int cal(int n){
    int nn = n - 1LL;
    int x = n * (n + 1LL) % mod;
    int y = (2 * n + 1) % mod;
    int tot = (x * y) % mod;
    tot *= modInv(6, mod - 2);
    int yo = tot - (n * n);
    yo %= mod;
    int s = nn * (nn + 1LL) / 2LL;
    yo += s;
    tot %= mod;
    yo %= mod;
    tot += yo;
    tot %= mod;
    return (tot * 2022LL) % mod;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        int n;
        cin >> n;
        cout << cal(n) << '\n';
    }
    return 0;
}
