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
    int tt;
    cin >> tt;
    while(tt--){
      long long c, m, x, ans = 0;
      cin >> c >> m >> x;
      long long l = 0, r = min<long long>(c, m);
      while(l <= r){
        long long mid = (l + r) >> 1;
        if((c + m + x) / 3 >= mid){
          ans = mid;
          l = mid + 1;
        }else r = mid - 1;
      }
      cout << ans << '\n';
    }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
