#include<bits/stdc++.h>
using namespace std;

bool possible(vector<long long> &ar, int n, long long lim, long long tot_pow){
    long long take = 0, temp = n, cnt;
    for(int i = 0; i < n; i++){
       cnt = tot_pow / ar[i] + 1;
       if(temp - cnt >= 0) take++, temp -= cnt;
    }
    return take >= lim;
}

int32_t main(){
     ios_base::sync_with_stdio(0);
      cin.tie(0); 
      #ifndef ONLINE_JUDGE 
      freopen("input.txt","r",stdin); 
      freopen("output.txt","w",stdout); 
      #endif
      auto start=clock();
      long long n, m;
      cin >> n >> m;
      vector<long long> ar(n);
      for(int i = 0; i < n; i++){
        cin >> ar[i];
      }
      sort(ar.rbegin(), ar.rend());
      long long l = 0, r = n, ans = 0;
      while(l <= r){
        long long mid = (l + r) >> 1LL;
        if(possible(ar, n, mid, m)){
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
      }
      cout << ans << '\n';
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
