#include<bits/stdc++.h>
using namespace std;

int steins(int a,int b){
   if(!a){
      return b;
   }
   if(!b){
      return a;
   }
   int k;
   for(k=0;!((a|b)&1);k++){
      a>>=1;
      b>>=1;
   }
   while(!(a&1)){
      a>>=1;
   }
   do{
      while(!(b&1)){
         b>>=1;
      }
      if(a>b)swap(a,b);

      b=(b-a);
   }while(b!=0);
   
return a<<k;
}

int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    auto st=clock();
    int a,b;
    cin>>a>>b;
    cout<<steins(a,b);
   cerr<< 1.0 * (clock()-st)/CLOCKS_PER_SEC<<'\n';
   return 0;
}
