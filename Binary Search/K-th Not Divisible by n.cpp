#include<bits/stdc++.h>
using namespace std;

long long good(long long n, long long x){
    long long res = x - (x / n);
    return res;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
    long long n, k;
    cin >> n >> k;
    long long l = 0, r = n * k;
    while(l <= r){
        long long mid = (l + r) >> 1;
        if(good(n, mid) == k && mid % n){
        cout << mid << '\n';
        break;
        }
        if(good(n, mid) < k){
          l = mid + 1;
        }else r = mid - 1;
      }
    }
    return 0;
}
