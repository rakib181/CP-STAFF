#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int p = 31, mod = 1e9 + 7, pw[N + 1];

void pre(){
pw[0] = 1;
for(int i = 1; i < N; i++){
   pw[i] = 1LL * pw[i - 1] * p % mod;
  }
}

int hash1(string s){
   int n = s.size(), ans = 0;
   for(int i = 0; i < n; i++){
     ans += 1LL * (s[i] - 'a' + 1) * pw[i] % mod;
     ans %= mod;
   }
   return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
     cin.tie(0); 
     #ifndef ONLINE_JUDGE 
     freopen("input.txt","r",stdin); 
     freopen("output.txt","w",stdout); 
     #endif
     auto start=clock();
     pre();
     string a, b;
     cin >> a >> b;
     cout << hash1(a) << ' ' << hash1(b) << '\n';
     cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
     return 0;
}
