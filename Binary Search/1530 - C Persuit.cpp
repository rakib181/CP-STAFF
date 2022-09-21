#include<bits/stdc++.h>
using namespace std;

bool possible(int mid, int n, vector<int> &ar, vector<int> &br){
    int k = mid - mid / 4;
    int j = n - min(n, k);
    int sum = 0;
    for(int i = n - 1; i >= j; i--){
       sum += br[i];
    }
    int in = 0;
    int ahead = min(k, mid - n);
    k -= ahead;
    in = ahead * 100; int i = n - 1;
    while(i >= 0 and k--){
      in += ar[i];
      i--;
    }
    return in >= sum;
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
      vector<int> ar(n), br(n);
      for(int i = 0; i < n; i++){
        cin >> ar[i];
      }
      for(int i = 0; i < n; i++){
        cin >> br[i];
      }
      sort(ar.begin(), ar.end());
      sort(br.begin(), br.end());
      int l = n, r = 1e7, ans = 0;
      while(l <= r){
        int mid = (l + r) >> 1;
        if(possible(mid, n, ar, br)){
          ans = mid;
          r = mid - 1;
        }else l = mid + 1;
      }
      cout << ans - n << '\n';
    }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
