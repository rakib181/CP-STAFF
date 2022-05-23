#include<bits/stdc++.h>
using namespace std;
const int N=1e6+15;
vector<int>v;
bool prime[N+1];
int cnt[N+1];

void sieve(){
    for(int i=4;i<=N;i+=2)prime[i]=1;
      for(int i=3;i*i<=N;i++){
         if(!prime[i]){
            for(int j=i*i;j<=N;j+=i+i){
               prime[j]=1;
            }
         }
      }
      cnt[2]=1;
      for(int i=3;i<=N;i++){
         if(!prime[i]){
            cnt[i]+=cnt[i-1]+1;
         }else{
            cnt[i]=cnt[i-1];
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
    sieve();
    int t;
    cin>>t;
    while(t--){
      int l,r;
      cin>>l>>r;
      cout<<cnt[r]-cnt[l-1];
   }
   cerr<< 1.0 * (clock()-st)/CLOCKS_PER_SEC<<'\n';
   return 0;
}
