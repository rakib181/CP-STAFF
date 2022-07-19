#include<bits/stdc++.h>
using namespace std;

const int N = 1e6, p1 = 137, p2 = 151, mod1 = 1e9 + 7, mod2 = 1e9 + 9;

int power(long long a, long long b, int mod){
   long long ans = 1;
   while(b){
      if(b & 1) ans = (ans * a) % mod;
      a = (a * a) % mod;
      b >>= 1;
   }
   return ans;
}
int ip1, ip2;
pair<int, int> pw[N], invpw[N];
void precal(){
  pw[0] = {1, 1};
  for(int i = 1; i < N; i++){
    pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
    pw[i].first %= mod1;
    pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
    pw[i].second %= mod2;
  }
  ip1 = power(p1, mod1 - 2, mod1);
  ip2 = power(p2, mod2 - 2, mod2);
  invpw[0] = {1, 1};
  for(int i = 1; i < N; i++){
    invpw[i].first = 1LL * invpw[i - 1].first * ip1 % mod1;
    invpw[i].first %= mod1;
    invpw[i].second = 1LL * invpw[i - 1].second * ip2 % mod2;
    invpw[i].second %= mod2;
  }
}
pair<int, int> pref[N];
void build(string s){
   int n = s.size();
   for(int i = 0; i < n; i++){
      pref[i].first = 1LL * s[i] * pw[i].first % mod1;
      if(i) pref[i].first = (pref[i].first + pref[i - 1].first) % mod1;
      pref[i].second = 1LL * s[i] * pw[i].second % mod2;
      if(i) pref[i].second = (pref[i].second + pref[i - 1].second) % mod2;
   }
}

pair<int, int> string_hash(string s){
   int n = s.size();
   pair<int, int> hs({0, 0});
   for(int i = 0; i < n; i++){
      hs.first += 1LL * s[i] * pw[i].first % mod1;
      hs.first %= mod1;
       hs.second += 1LL * s[i] * pw[i].second % mod2;
      hs.second %= mod2;
   }
   return hs;
}

pair<int, int> get_hash(int i, int j){
 assert(i <= j);
 pair<int, int> hs({0, 0});
 hs.first = pref[j].first;
 if(i) hs.first = (hs.first - pref[i - 1].first + mod1) % mod1;
 hs.first = (1LL * hs.first * invpw[i].first) % mod1;
  hs.second = pref[j].second;
 if(i) hs.second = (hs.second - pref[i - 1].second + mod2) % mod2;
 hs.second = (1LL * hs.second * invpw[i].second) % mod2;

 return hs;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
     cin.tie(0); 
     #ifndef ONLINE_JUDGE 
     freopen("input.txt","r",stdin); 
     freopen("output.txt","w",stdout); 
     #endif
     auto start=clock();
     precal();
     string a, b;
     cin >> a >> b;
     build(a);
     int ans = 0, n = a.size(), m = b.size();
     auto hash_b = string_hash(b);
     for(int i = 0 ; i + m - 1 < n; i++){
      ans += get_hash(i, i + m - 1) == hash_b;
     }
     cout << ans << '\n';
     cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
     return 0;
}
