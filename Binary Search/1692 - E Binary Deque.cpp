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
      int n, s;
      cin >> n >> s;
      vector<int> ar(n + 1); vector<long long> prefix(n + 2, 0);
      for(int i = 1; i <= n; i++){
         cin >> ar[i];
         prefix[i] = prefix[i - 1] + ar[i];
      } 
      int ans = INT_MAX;
      for(int i = 1; i <= n; i++){
        int l = i, r = n, target = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if((prefix[mid] - prefix[i - 1]) <= s){
                target = mid;
                l = mid + 1;
            }else r = mid - 1;
        }
        if(target == -1 || (prefix[target] - prefix[i - 1]) != s)continue;
        ans = min(ans, n - (target - i + 1));
      } 
      if(ans == INT_MAX)cout << "-1" << '\n';
      else cout << ans << '\n';  
      }
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
