#include<bits/stdc++.h>
using namespace std;

const int N = 101;

bool good(vector<int> &cnt, int x, int n){
    int c_d = 0;
    for(int i = 1; i < N; i++){
        if(cnt[i] >= x){
            c_d += cnt[i] / x;
        }
    }
    return c_d >= n;
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
      vector<int> ar(m); vector<int> cnt(N, 0);
      for(int i = 0; i < m; i++){
        cin >> ar[i];
        cnt[ar[i]]++;
      }
      int l = 1, r = 2 * m, ans = 0;
      while(l <= r){
        int mid = (l + r) >> 1;
        if(good(cnt, mid, n)){
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
      }
      cout << ans << '\n';
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
