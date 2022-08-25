#include<bits/stdc++.h>
using namespace std;

bool good(vector<int> &ar, int n, long long k, long long x){
    long long cnt = 0;
    for(int i = 0; i < n; i++){
        cnt += (ar[i] / x);
        if(cnt >= k)return true;
    }
    return false;
}

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
      long long n, k;
      cin >> n >> k;
      vector<int> ar(n);
      for(int i = 0; i < n; i++){
        cin >> ar[i];
      }
      long long l = 1, r = *max_element(ar.begin(), ar.end()), ans = 0;
      while(l <= r){
        long long mid  = (l + r) >> 1;
        if(good(ar, n, k, mid)){
            ans = max(ans, mid);
            l = mid + 1;
        }else r = mid - 1;
      }
      cout << ans << '\n';
      }
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
