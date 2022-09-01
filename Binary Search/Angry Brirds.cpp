#include<bits/stdc++.h>
using namespace std;

bool good(vector<int> &ar, int n, int p, int limit){
    int cnt = 1, cur_loc = ar[0];
    for(int i = 1; i < n; i++){
        if(ar[i] - cur_loc >= limit){
            cnt++;
            cur_loc = ar[i];
        }
        if(cnt >= p)return true;
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
      int n, p;
      cin >> n >> p;
      vector<int> ar(n);
      for(int i = 0; i < n; i++){
        cin >> ar[i];
      }    
      sort(ar.begin(), ar.end());
      int l = 0, r = ar[n - 1] - ar[0], ans = 0;
      while(l <= r){
        int mid = (l + r) >> 1;
        if(good(ar, n, p, mid)){
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
      }
      cout << ans << '\n';
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
