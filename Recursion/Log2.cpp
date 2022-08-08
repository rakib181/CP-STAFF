#include<bits/stdc++.h>
using namespace std;

int rec(long long n){
    if(n == 0)return 0;
    return 1 + rec(n / 2);
}

int32_t main(){
     ios_base::sync_with_stdio(0);
      cin.tie(0); 
      #ifndef ONLINE_JUDGE 
      freopen("input.txt","r",stdin); 
      freopen("output.txt","w",stdout); 
      #endif
      auto start=clock();
      long long n;
      cin >> n;
      cout << rec(n) - 1 << '\n';
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
