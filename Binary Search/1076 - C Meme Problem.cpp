#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-10;

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
       double n;
      cin >> n;
      if(n == 0){
        cout << "Y" << ' ' << fixed << setprecision(9) << 0.0 << ' ' << 0.0 << '\n';
        continue;
      }
      if(n < 4){
        cout << "N" << '\n';
        continue;
      }
      double sq = n * (n - 4.0);
      double l = 0.0, r = sq;
      while((r - l) > eps){
         double mid = (l + r) / 2.0;
         if(mid * mid < sq) l = mid;
         else r = mid; 
      }
      double a = (n + l) / 2.0, b = (n - l) / 2.0;
      cout << "Y" << ' ' << fixed << setprecision(9) << a << ' ' << b << '\n';

    }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
