#include<bits/stdc++.h>
using namespace std;

bool good(vector<int> &ar, int n, int m, int limit){
    int cnt = 1, sum = 0;
    for(int i = 0; i < n; i++){
        if(ar[i] > limit)return false;

        if(sum + ar[i] > limit){
            cnt++;
            sum = ar[i];
        }else {
            sum += ar[i];
        }
    }
    return cnt <= m;
}

int32_t main(){
     ios_base::sync_with_stdio(0);
      cin.tie(0); 
      #ifndef ONLINE_JUDGE 
      freopen("input.txt","r",stdin); 
      freopen("output.txt","w",stdout); 
      #endif
      auto start=clock();
      int n, m;
      cin >> n >> m;
      vector<int> ar(n);
      for(int i = 0; i < n; i++){
        cin >> ar[i];
      }
      int l = 0 , r = accumulate(ar.begin(), ar.end(), 0LL), ans = 0;
      while(l <= r){
        int mid = (l + r) >> 1;
        if(good(ar, n, m, mid)){
            ans = mid;
            r = mid - 1;
        }else l = mid + 1;
      }
      cout << ans << '\n';
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
