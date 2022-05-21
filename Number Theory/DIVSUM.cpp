#include<bits/stdc++.h>
using namespace std;

long long solve(int n){
   int sod=1,tmp=n;
	for(int i=2,p;i*i<=n;i++){
      p=i;
      while(!(tmp%i)){
         tmp/=i;
         p*=i;
      }
      if(i!=p)sod*=(p-1)/(i-1);
   }
   if(tmp>1)sod*=(tmp*tmp-1)/(tmp-1);
   return sod-n;
}

int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    auto st=clock();
    int t; 
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    cout<<solve(n)<<endl;
    }
   cerr<< 1.0 * (clock()-st)/CLOCKS_PER_SEC<<'\n';
   return 0;
}
