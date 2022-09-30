#include<bits/stdc++.h>
using namespace std;

bool possible(vector<pair<int, int>> &ar, int n, long long x, vector<long long> &suff){
    int l = -1, r = n, ans = 0;
    while(r > l + 1){
        int mid = (l + r) >> 1;
        if(ar[mid].first > x){
            r = mid;
        }else {
            l = mid;
        }
    }
    int rem = n - (l + 1);
    if(suff[rem - 1] <= x)return true;
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
      int n;
      cin >> n;
      vector<pair<int, int>> ar(n);
      for(int i = 0; i < n; i++){
        cin >> ar[i].first;
      }
      for(int i = 0; i < n; i++){
        cin >> ar[i].second;
      }
      sort(ar.begin(), ar.end());
      vector<long long> suff(n, 0);
      suff[n - 1] = ar[n - 1].second;
      for(int i = n - 2; i >= 0; i--){
        suff[i] = suff[i + 1] + ar[i].second;
      }
      reverse(suff.begin(), suff.end());
      long long l = 0, r = ar[n - 1].first, ans = r;
      while(l <= r){
        long long mid = (l + r) >> 1;
        if(possible(ar, n, mid, suff)){
            ans = mid;
            r = mid - 1;
        }else l = mid + 1;
      }
      cout << ans << '\n';
    }
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
