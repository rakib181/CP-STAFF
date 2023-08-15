#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int mul_mod(int x, int y){
    int ans = 0;
    while (y){
        if(y & 1)ans = 1LL * (1LL * ans + x) % MOD;
        x = 1LL * (1LL * x + x) % MOD;
        y >>= 1;
    }
    return ans;
}

int f(int n){
    if(n <= 0)return 0;
    int i = 1, c = 1, add = 1, cnt = 0;
    while(add <= n){
        cnt = 1LL * (1LL * cnt + mul_mod(c, i)) % MOD;
        c += 1;
        i <<= 1;
        add += i;
    }
    add -= i;
    int rem = n - add;
    if(rem > 0) {
        cnt =  1LL * (1LL * cnt + mul_mod(c, rem)) % MOD;
    }
    return cnt;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << 1LL * (1LL * f(r) - f(l - 1) + MOD) % MOD << '\n';
    }
    return 0;
}
