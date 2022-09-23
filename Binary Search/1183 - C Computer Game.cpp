#include<bits/stdc++.h>
using namespace std;

int32_t main(){
     ios_base::sync_with_stdio(0);
      cin.tie(0); 
      #ifndef ONLINE_JUDGE 
      freopen("input.txt","r",stdin); 
      freopen("output.txt","w",stdout); 
      #endif
      auto start=clock();
      int q;
      cin >> q;
      while(q--){
        long long n, k, a, b;
        cin >> n >> k >> a >> b;
        long long l = 0, r = k, ans = -1;
        while(l <= r){
            long long mid = (l + r) >> 1;
            if(mid * a < n and (k - mid) * b + mid * a < n){
                ans = mid;
                l = mid + 1;
            }else r = mid - 1;
        }
        cout << ans << '\n';
      }
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
