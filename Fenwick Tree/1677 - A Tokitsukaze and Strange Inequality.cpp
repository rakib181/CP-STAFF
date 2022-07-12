#include<bits/stdc++.h>
using namespace std;
 struct fenwick
{
  vector<int>fn;
  int n;
  void init(int n){
   this -> n = n + 5;
   fn.resize(this -> n, 0);
  } 

  void add(int x,int val){
   while(x < n){
      fn[x] += val;
      x += x & (-x);
   }
  }
  int sum(int x){
   int sum = 0;
   while(x){
     sum += fn[x];
     x -= x & (-x);
   }
   return sum;
  }
  void reset(){
   for(int i = 0; i < n; i++){
      fn[i] = 0;
   }
  }
};
int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    auto st=clock();
    fenwick fp;
    fenwick fs;
    int tt;
    cin >> tt;
    while(tt--){
    int n; long long res = 0;
    cin >> n;
    fp.init(n);
    fs.init(n);
    fp.reset();
    int a[n];
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < n; i++){
      fs.reset();
      for(int j = n - 1; j > i; j--){
          res += 1LL * fp.sum(a[j]) * 1LL * fs.sum(a[i]);
          fs.add(a[j], 1);
      }
      fp.add(a[i], 1);
    }
    cout << res << '\n';
 }
   cerr<< 1.0 * (clock()-st)/CLOCKS_PER_SEC<<'\n';
   return 0;
}
