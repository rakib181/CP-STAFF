#include <bits/stdc++.h>
using namespace std;

bool possible(vector<long long> &ar, int t, long long x, int n){
   long long cnt = 0;
   for(int i = 0; i < n; i++){
      if(ar[i] <= x) cnt += (x / ar[i]);
      if(cnt >= t)return true;
   }
   return false;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    cin >> n >> t;
    vector<long long> ar(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }
    long long l = 0, r = 2e18, ans = 0;
    while (l <= r){
        long long mid = (l + r) >> 1LL;
        if(possible(ar, t, mid, n)){
            ans = mid;
            r = mid - 1;
        }else l = mid + 1;
    }
    cout << ans << '\n';
    return 0;
}
