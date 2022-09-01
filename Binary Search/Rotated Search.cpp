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
      int n, key;
      cin >> n >> key;
      vector<int> ar(n);
      for(int i = 0; i < n; i++){
        cin >> ar[i];
      }    
      int l = 0, r = n - 1;
      while(l <= r){
        int mid = (l + r) >> 1;
        if(ar[mid] == key){
            cout << mid << '\n';
            return 0;
        }

        if(ar[l] <= ar[mid]){
           if(ar[mid] >= key and ar[l] <= key){
             r = mid - 1;
           }else l = mid + 1;
        }else{
           if(ar[mid] <= key && ar[r] >= key){
            l = mid + 1;
           }else r = mid - 1;
        }
      }
      cout << "-1" << '\n';
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
