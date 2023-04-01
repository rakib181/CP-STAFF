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
#include<bits/stdc++.h>
using namespace std;
#define int long long int
int k, x;

int get_sum(int n){
    return n * (n + 1) / 2;
}

int get_range_sum(int l, int r){
    return get_sum(r) - get_sum(l - 1);
}
bool good(int i){
    int s;
    if(i <= k){
        s = get_range_sum(1, i);
    }else{
        s = get_range_sum(1, k) + get_range_sum(2 * k - i, k - 1);
    }
    return s >= x;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--) {
       cin >> k >> x;
       int l = 1, r = 2 * k - 1, ans = 2 * k - 1;
       while(l <= r){
           int m = (l + r) >> 1;
           if(good(m)){
               ans = m;
               r = m - 1;
           }else l = m + 1;
       }
       cout << ans << '\n';
    }
    return 0;
}
