#include<bits/stdc++.h>
using namespace std;
int HbinarySearch(int linear[],int n,int x){
  int l=-1,r=n;
     while(r>l+1){
     int mid =(l+r)/2;
     if(linear[mid]<x){
      l=mid;
     }else{
       r=mid;
     } 
    }
    return r;
}
int LbinarySearch(int linear[],int n,int x){
  int l=-1,r=n;
     while(r>l+1){
     int mid =(l+r)/2;
     if(linear[mid]<=x){
      l=mid;
     }else{
       r=mid;
     } 
    }
    return r;
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
    int n;
    cin>>n;
    int linear[n];
    for(int i=0;i<n;i++){
      cin>>linear[i];
    }
    sort(linear,linear+n);
    int q;cin>>q;
    while(q--){
    int x,y;cin>>x>>y;
    int ans = HbinarySearch(linear,n,x);
    int ans1 = LbinarySearch(linear,n,y);
    cout<<ans1-ans<<'\n';
  }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
