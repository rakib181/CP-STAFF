#include <bits/stdc++.h>
using namespace std;

long long progression(long long x){
    return x * (x + 1LL) / 2LL;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        long long k, x;
        cin >> k >> x;
        long long l = 1LL, r = 2LL * k - 1LL, ans = 2LL * k - 1LL;
        while(l <= r){
            long long mid = (l + r) >> 1LL;
            if((mid <= k and progression(mid) < x) or (mid > k and progression(k) + progression(k - 1) - progression((2 * k - 1) - mid) < x)){
                l = mid + 1LL;
            }else{
                ans = mid;
                r = mid - 1LL;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
