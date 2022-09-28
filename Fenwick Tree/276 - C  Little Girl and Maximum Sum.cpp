#include<bits/stdc++.h>
using namespace std;

struct fenwick
{
  vector<long long> fn;
  int n;
  void init(int n){
   this -> n = n + 1000;
   fn.resize(this -> n, 0);
  } 

  void add(int x, int val){
   ++x;
   while(x <= n){
      fn[x] += val;
      x += x & (-x);
   }
  }
  long long sum(int x){
   ++x; long long sum = 0;
   while(x){
     sum += fn[x];
     x -= x & (-x);
   }
   return sum;
  }
}tree;


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
     tree.init(n);
     vector<long long> ar(n + 1);
     for(int i = 1; i <= n; i++)cin >> ar[i];
     sort(ar.begin(), ar.end());
     while(m--){
      int l, r;
      cin >> l >> r;
      tree.add(l, 1);
      tree.add(r + 1, -1);
     }
     vector<long long> cnt(n + 1);
     for(int i = 1; i <= n; i++){
      cnt[i] = tree.sum(i);
     }
     sort(cnt.begin(), cnt.end()); long long ans = 0;
     for(int i = 1; i <= n; i++)ans += (ar[i] * cnt[i]);
     cout << ans << '\n';
     cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
     return 0;
}
