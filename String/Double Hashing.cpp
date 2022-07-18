#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int p1 = 31, p2 = 37, mod1 = 1e9 + 7, mod2 = 1e9 + 9, pw1[N + 1], pw2[N + 1];

void pre(){
pw1[0] = 1;
for(int i = 1; i < N; i++){
   pw1[i] = 1LL * pw1[i - 1] * p1 % mod1;
  }
  pw2[0] = 1;
  for(int i = 1; i < N; i++){
   pw2[i] = 1LL * pw2[i - 1] * p2 % mod2;
  }
}

pair<int, int> hash1(string s){
   int n = s.size(), ans1 = 0, ans2 = 0;
   for(int i = 0; i < n; i++){
     ans1 += 1LL * (s[i] - 'a' + 1) * pw1[i] % mod1;
     ans1 %= mod1;
   }
   for(int i = 0; i < n; i++){
     ans2 += 1LL * (s[i] - 'a' + 1) * pw2[i] % mod2;
     ans2 %= mod2;
   }
   return {ans1, ans2};
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
     cout << hash1(a).first << ' ' << hash1(b).first << '\n';
     cout << hash1(a).second << ' ' << hash1(b).second << '\n';
     cout << (hash1(a) == hash1(b)) << '\n';
     cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
     return 0;
}
