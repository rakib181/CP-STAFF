#include <bits/stdc++.h>
using  namespace std;

long long square(long long x){
    long long l = 0, r = 2e9, ans = 0;
    while(l <= r){
        long long mid = (l + r) >> 1LL;
        if(mid * mid <= x){
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
    }
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        long long l, r, ans;
        cin >> l >> r;
        long long sq_l = square(l), sq_r = square(r);
        if(sq_l == sq_r){
           ans = 0;
            for(int i = 0; i <= 2; i++){
                if(l <= sq_l * (sq_l + i) and sq_l * (sq_l + i) <= r)ans++;
            }
        }else{
           ans = (sq_r - sq_l - 1) * 3LL;
            for(int i = 0; i <= 2; i++){
                if(l <= sq_l * (sq_l + i) and sq_l * (sq_l + i) <= r)ans++;
                if(l <= sq_r * (sq_r + i) and sq_r * (sq_r + i) <= r)ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
