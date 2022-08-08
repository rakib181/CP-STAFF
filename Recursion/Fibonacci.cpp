#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

int dp[N];
int fib(int n){
    if(n == 2 || n == 3)return 1;
    if(dp[n] != -1)return dp[n];
    return dp[n] = fib(n - 1) + fib(n - 2);
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
      memset(dp, -1, sizeof dp);
      cout << fib(n) << '\n';
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
