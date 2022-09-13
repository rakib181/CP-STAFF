#include<bits/stdc++.h>
using namespace std;

long long good(vector<long long> &ar, int n, int mid){
    long long sum = 0;
    for(int i = 0; i < mid; i++){
        sum += (n - ar[i]);
    }
    return sum;
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
      int n, m;
      cin >> n >> m;
      vector<long long> ar(m);
      for(int i = 0; i < m; i++){
          cin >> ar[i];
      }
      sort(ar.rbegin(), ar.rend());
      int l = 0, r = m, ans = 0;
      while(l <= r){
        int mid = (l + r) >> 1;
        if(good(ar, n, mid) < n){
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
      }
      cout << ans << '\n';
      }
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
