#include<bits/stdc++.h>
using namespace std;

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
      int n, q;
      cin >> n >> q;
      int a[n + 1], b[n + 1];
      for(int i = 1; i <= n; i++)cin >> a[i];
      auto check = [&](int x){
        for(int i = 1; i <= n; i++)b[i] = 0;
        int nq = q;
        for(int i = 1; i < x; i++){
         if(a[i] <= nq)b[i] = 1;
        }
        for(int i = x; i <= n; i++){
         b[i] = 1;
         if(!nq)return 0;
         if(a[i] > nq) nq--;
        }
        if(nq < 0)return 0;
        return 1;
      };

     int l = 1, r = n;
     while(l <= r){
      int mid = (l + r) >> 1;
      if(check(mid)){
         r = mid - 1;
      }else{
         l = mid + 1;
      }
    }
    check(r + 1);
    for(int i = 1; i <= n; i++){
      cout << b[i];
    }
    cout << '\n';
  }
     cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
     return 0;
}
