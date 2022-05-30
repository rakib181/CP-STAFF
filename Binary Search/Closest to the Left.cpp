#include<bits/stdc++.h>
using namespace std;
int binarySearch(int linear[],int n,int x){
  int l=-1,r=n;
     while(r>l+1){
     int mid =(l+r)/2;
     if(linear[mid]<=x){
      l=mid;
     }else{
       r=mid;
     } 
    }
    return l+1;
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
    int n,q;
    cin>>n>>q;
    int linear[n];
    for(int i=0;i<n;i++){
      cin>>linear[i];
    }
    while(q--){
    int x;cin>>x;
    int ans = binarySearch(linear,n,x);
    cout<<ans<<'\n';
  }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
