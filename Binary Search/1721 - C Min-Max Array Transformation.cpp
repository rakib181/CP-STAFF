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
        int n;
        cin >> n;
        vector<int> ar(n), br(n), mn(n), mx(n);
        for(int i = 0; i < n; i++)cin >> ar[i];
        for(int i = 0; i < n; i++)cin >> br[i];
        for(int i = 0; i < n; i++){
            int l = 0, r = n - 1, ans = 0;
            while(l <= r){
                int mid = (l + r) >> 1;
                if(br[mid] >= ar[i]){
                   ans = br[mid];
                   r = mid - 1;
                }else l = mid + 1;
            }
            mn[i] = (ans - ar[i]);
        }
        int pt = n - 1;
        for(int i = n - 1; i >= 0; i--){
           mx[i] = (br[pt] - ar[i]);
           if(ar[i] > br[i - 1]) pt = i - 1;
        }
        for(int i = 0; i < n; i++){
            cout << mn[i] << ' ';
        }
        cout << '\n';
        for(int i = 0; i < n; i++){
            cout << mx[i] << ' ';
        }
        cout << '\n';
      }
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
