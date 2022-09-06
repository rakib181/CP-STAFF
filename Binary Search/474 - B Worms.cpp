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
      int n;
      cin >> n;
      vector<int> ar(n + 1); vector<long long> prefix(n + 2, 0);
      for(int i = 1; i <= n; i++){
         cin >> ar[i];
         prefix[i] = prefix[i - 1] + ar[i];
      }
      int q;
      cin >> q;
      while(q--){
        int qi;
        cin >> qi;
      int l = 1, r = n, ans = -1;
      while(l <= r){
        int mid = (l + r) >> 1;
        if(prefix[mid] >= qi && prefix[mid - 1] < qi){
            ans = mid;
           break;
        }
        if(prefix[mid] < qi){
            l = mid + 1;
        }else {
            r = mid - 1;
        }
        }
        cout << ans << '\n';
      }
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
