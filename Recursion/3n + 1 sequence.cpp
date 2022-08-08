#include<bits/stdc++.h>
using namespace std;

int rec(int n){
    if(n == 1) return 1;
    if(n % 2 == 0)return 1 + rec(n / 2);
    else return 1 + rec(3 * n + 1);
}

int32_t main(){
     ios_base::sync_with_stdio(0);
      cin.tie(0); 
      #ifndef ONLINE_JUDGE 
      freopen("input.txt","r",stdin); 
      freopen("output.txt","w",stdout); 
      #endif
      auto start=clock();
      int n;
      cin >> n;
      cout << rec(n) << '\n';
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
