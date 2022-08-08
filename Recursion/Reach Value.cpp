#include<bits/stdc++.h>
using namespace std;
bool found = false;
void rec(long long i, long long n){
    if(i > n)return;
    if(i == n){
      found = true;
      return;
    }
    rec(i * 10, n);
    rec(i * 20, n);
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
      long long n;
      cin >> n;
      rec(1, n);
      if(found){
        cout << "YES" << '\n';
      }else cout << "NO" << '\n';
      found = false;
  }
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
