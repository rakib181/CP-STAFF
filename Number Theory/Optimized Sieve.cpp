#include<bits/stdc++.h>
using namespace std;

const int MX=1e8;
vector<bool>prime(MX+1,0);
void letsGo(){
   prime[1]=1;
   for(int i=4;i<=MX;i+=2)prime[i]=1;
   for(int i=2;i*i<=MX;i++){
      if(!prime[i]){
         for(int j=i*i;j<=MX;j+=i+i){
            prime[j]=1;
         }
      }
   }
   for(int i=1,cnt=0,n=1;i<=MX;i++){
      if(!prime[i]){
         cnt++;
         if(cnt==n){
            n+=100;
            cout<<i<<endl;
         }
      }
   }
}

int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    auto st=clock();
    letsGo();
   cerr<< 1.0 * (clock()-st)/CLOCKS_PER_SEC<<'\n';
   return 0;
}
