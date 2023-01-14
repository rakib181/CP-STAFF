#include<bits/stdc++.h>
using namespace std;
#define int long long int
using u64 = uint64_t;
using u128 = __uint128_t;
u64 bin(u64 x, u64 y, u64 MOD){
    u64 ans = 1;
    x %= MOD;
    while (y){
        if(y & 1) ans = (u128) ans * x % MOD;
        x = (u128) x * x % MOD;
        y >>= 1;
    }
    return ans;
}

bool check_composite(u64 n, u64 a, u64 d, int s){
    u64 x = bin(a, d, n);
    if(x == 1 or x == n - 1)return false;
    for(int i = 1; i <= s; i++){
        x = (u128) x * x % n;
        if(x == n - 1)return false;
    }
    return true;
}

bool millerRobin(u64 n){
    if(n < 2)return false;
    u64 d = n - 1; int s = 0;
    while (!(d & 1)){
        d >>= 1;
        s++;
    }
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        int n;
        cin >> n;
        if(millerRobin(n)){
            cout << n << " is a prime" << '\n';
        }else{
            cout << n <<  " is not a prime" << '\n';
        }
    }
    return 0;
}
