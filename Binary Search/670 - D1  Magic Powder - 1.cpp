#include<bits/stdc++.h>
using namespace std;

bool possible(vector<pair<int, int>> &have, int n, int mid, int k){
    for(int i = 0; i < n; i++){
        if(have[i].first * mid > have[i].second){
            int need = (have[i].first * mid) - have[i].second;
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
      int n, k;
      cin >> n >> k;
      vector<pair<int, int>> have(n);
      for(int i = 0; i < n; i++){
        cin >> have[i].first;
      }
      for(int i = 0; i < n; i++){
        cin >> have[i].second;
      }
      int l = 0, r = 10000, ans = 0;
      while(l <= r){
        int mid = (l + r) >> 1;
        if(possible(have, n, mid, k)){
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
      }
      cout << ans << '\n';
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
