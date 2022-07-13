#include<bits/stdc++.h>
using namespace std;

struct fenwick{
 
   int n;
   vector<int> fn;
   void init(int n){
      this -> n = n + 10;
      fn.resize(this -> n, 0);
   }
   void add2(int x, int val){
      while(x <= n){
       fn[x] += val;
       x += x & (-x);
      }
   }
   int sum(int x){
      int sum = 0;
      while(x > 0){
         sum += fn[x];
         x -= x & (-x);
      }
      return sum;
   }
   int sum(int l, int r){
      return sum(r + 1) - sum(l);
   }
};


int32_t main(){
    ios_base::sync_with_stdio(0);
     cin.tie(0); 
     #ifndef ONLINE_JUDGE 
     freopen("input.txt","r",stdin); 
     freopen("output.txt","w",stdout); 
     #endif
     auto start=clock();
     int tt, idx = 1;
     cin >> tt;
     while(tt--){
      cout << "Case " << idx++ << ":" << '\n';
     int n, q;
     cin >> n >> q;
     fenwick FEN;
     FEN.init(n);
     int a[n];
     for(int i = 1; i <= n; i++){
       cin >> a[i];
       FEN.add2(i, a[i]);
     }
     while(q--){
      int x;
      cin >> x;
      if(x == 1){
         int i;
         cin >> i;
         int val = a[i + 1];
         cout << val <<'\n';
         a[i + 1] = 0;
        FEN.add2(i + 1, -val);
      }else if(x == 2){
         int i, v; cin >> i >> v;
         a[i + 1] += v;
         FEN.add2(i + 1, v);
      }else{
         int l, r;
         cin >> l >> r;
         cout << FEN.sum(l, r) << '\n';
      }
     }
    } 
     cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
     return 0;
}
