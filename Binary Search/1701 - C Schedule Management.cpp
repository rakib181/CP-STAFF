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
      int n, m;
      cin >> n >> m;
      vector<int> v(m + 1), cnt(n + 1);
      for(int i = 1; i <= m; i++){
        cin >> v[i];
        cnt[v[i]]++;
      }

      auto good = [&](int t){
         long long free = 0, need = 0;
         for(int i = 1; i <= n; i++){
          if(t >= cnt[i]){
            free += (t - cnt[i]) >> 1;
          }else{
            need += cnt[i] - t;
          }
         }
         return need <= free;
      };

      int l = 1, r = m << 1, ans = -1;
      while(l <= r){
        int mid = (l + r) >> 1;
        if(good(mid)){
          ans = mid;
          r = mid - 1;
        }else{
          l = mid + 1;
        }
      }
      cout << ans << '\n';
    }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
