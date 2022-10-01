#include<bits/stdc++.h>
using namespace std;

bool possible(vector<pair<long long, long long>> &have, int n, long long mid, long long k){
    for(int i = 0; i < n; i++){
        if(have[i].first * mid > have[i].second){
            long long need = (have[i].first * mid) - have[i].second;
            if(k - need >= 0)k -= need;
            else return false;
        }
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
      long long n, k;
      cin >> n >> k;
      vector<pair<long long, long long>> have(n);
      for(int i = 0; i < n; i++){
        cin >> have[i].first;
      }
      for(int i = 0; i < n; i++){
        cin >> have[i].second;
      }
      long long l = 0, r = 1e10, ans = 0;
      while(l <= r){
        long long mid = (l + r) >> 1LL;
        if(possible(have, n, mid, k)){
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
      }
      cout << ans << '\n';
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
