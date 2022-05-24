#include<bits/stdc++.h>
using namespace std;

int legendres(int n,int p){
   int ans=0;
   while(n){
      ans+=n/p;
      n/=p;
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
    auto st=clock();
   int n,p,cnt=0;
   cin>>n>>p;
   cout<<legendres(n,p)<<endl;
   cerr<< 1.0 * (clock()-st)/CLOCKS_PER_SEC<<'\n';
   return 0;
}
