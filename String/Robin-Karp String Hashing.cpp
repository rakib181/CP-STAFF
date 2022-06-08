#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7,p=31;

int poly_hash(string s){
  int hash=0,p_pow=1;
  for(int i=0;i<s.size();i++){
    hash+=(s[i]-'a'+1)*p_pow;
    p_pow*=p;
    hash%=mod;
    p_pow%=mod;
  }
  return hash;
}

int pow(int a,int b){
  int res=1;
  while(b){
  if(b&1)res*=a;
  b>>=1;
  a*=a;
  a%=mod;
  res%=mod;
}
return res;
}

int inv(int x){
  return pow(x,mod-2);
}

int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    #endif
    auto start=clock();
    string text,pattern;
    cin >> text >> pattern;
    int n=text.size(),m=pattern.size();
    int pat_hash=poly_hash(pattern);
    int text_hash=poly_hash(text.substr(0,m));
      bool ok=false;
    if(pat_hash==text_hash){ok=true;cout << "0" << '\n';}
    for(int i=1;i+m<=n;i++){
      text_hash = (text_hash - (text[i-1] - 'a' + 1) + mod) % mod;

      text_hash = (text_hash * inv(p))%mod;

      text_hash = (text_hash + (text[i+m-1] - 'a' + 1) * pow(p,m-1))%mod;
      if(pat_hash==text_hash){ok=true;cout << i << '\n';}
    }
    if(!ok)cout << "Not Found ! ";
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
