#include<bits/stdc++.h>
using namespace std;

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
     int ar[n/32];
     for(int i=0;i<n;i++){
               cin>>ar[1<<i>>1];
      }
      for(int i=0;i<n;i++){
            cout<<ar[1<<i>>1]<<' ';
      }
    }
   cerr<< 1.0 * (clock()-st)/CLOCKS_PER_SEC<<'\n';
   return 0;
}
