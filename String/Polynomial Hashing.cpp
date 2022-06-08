#include<bits/stdc++.h>
using namespace std;
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

int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    #endif
    auto start=clock();
    string s;
    cin >> s;
    cout << poly_hash(s);
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
