#include<bits/stdc++.h>
using namespace std;

bool good(long long r, long long b, long long g, long long mid){
    return (r - mid) + (b - mid) + g >= mid;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        long long n, r, g, b;
        cin >> n >> r >> g >> b;
        long long low = 0, high = min({n, r, b}), ans = 0;
        while (low <= high){
            long long mid = (low + high) >> 1;
            if(good(r, b, g, mid)){
                ans = mid;
                low = mid + 1;
            }else high = mid - 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
