#include<bits/stdc++.h>
using namespace std;

bool possible(vector<long long> &ar, long long n, long long m, long long limit){
    long long tot_cut = 0;
    for(int i = 0; i < n; i++){
        if(ar[i] > limit) tot_cut += (ar[i] - limit);

        if(tot_cut >= m)return true;
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
      long long n, m;
      cin >>  n >> m;
      vector<long long> ar(n);
      for(int i = 0; i < n; i++){
        cin >> ar[i];
      }
      long long l = 0, r = accumulate(ar.begin(), ar.end(), 0LL), ans = 0;

      while(l <= r){
         long long mid = (l + r) >> 1;
         if(possible(ar, n, m, mid)){
            ans = mid;
            l = mid + 1;
         }else r = mid - 1;
      }
      cout << ans << '\n';
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
