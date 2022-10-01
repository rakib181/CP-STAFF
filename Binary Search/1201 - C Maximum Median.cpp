#include<bits/stdc++.h>
using namespace std;

bool possible(vector<long long> &ar, int idx, int n, long long x, int k){
       long long cnt = 0;
       for(int i = idx; i < n; i++){
          if(x >= ar[i])cnt += (x - ar[i]);
          if(cnt > k)return false;
       }
       return true;
}

int32_t main(){
     ios_base::sync_with_stdio(0);
      cin.tie(0); 
      #ifndef ONLINE_JUDGE 
      freopen("input.txt","r",stdin); 
      freopen("output.txt","w",stdout); 
      #endif
      auto start=clock();
      int n, k;
      cin >> n >> k;
      vector<long long> ar(n);
      for(int i = 0; i < n; i++){
        cin >> ar[i];
      }
      sort(ar.begin(), ar.end());
      long long l = 1, r =  2e9, ans = 1;
      while(l <= r){
        long long mid = (l + r) >> 1;
        if(possible(ar, n / 2, n, mid, k)){
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
      }
      cout << ans << '\n';
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
