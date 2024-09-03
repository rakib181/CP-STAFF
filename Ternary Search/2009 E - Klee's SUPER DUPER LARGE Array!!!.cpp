#include<bits/stdc++.h>
using namespace std;

#define long long long int

const long inf = 2e9;

long get(long n){
    return n * (n + 1) / 2;
}

long fun(long l, long r){
    if(l > r)return 0;
    return get(r) - get(l - 1);
}

long f(long m, long n, long k){
    return abs(fun(k, m) - fun(m + 1, n + k - 1));
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
       long n, k;
       cin >> n >> k;
       long l = k, r = n + k - 1, ans = k;
       while(l <= r){
           long m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
           if(f(m1, n, k) > f(m2, n, k)){
               l = m1 + 1;
           }else if(f(m1, n, k) < f(m2, n, k)){
               r = m2 - 1;
           }else{
               ans = m2;
               l = m1 + 1, r = m2 - 1;
           }
       }
       cout << f(ans, n, k) << '\n';
    }
    return 0;
}
