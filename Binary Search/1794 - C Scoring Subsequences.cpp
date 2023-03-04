#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
      int n;
      cin >> n;
      vector<int> a(n + 1);
      for(int i = 1; i <= n; i++){
          cin >> a[i];
          int l = 1, r = i, ans = 1;
          while (l <= r){
              int m = (l + r) >> 1;
              if(a[i - m + 1] >= m){
                  ans = m;
                  l = m + 1;
              }else r = m - 1;
          }
          cout << ans << ' ';
      }
      cout << '\n';
    }
    return 0;
}
