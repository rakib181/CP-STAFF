#include<bits/stdc++.h>
using namespace std;
int binarySearch(int linear[],int i,int j,int x){
     while(i<=j){
    int mid =(i+j)/2;
    if(linear[mid]==x){
      return mid;
     }
     if(linear[mid]>=x){
      j=mid-1;
     }else{
      i=mid+1;
      }
    }
    return -1;
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
    int linear[n+1];
    for(int i=1;i<=n;i++){
      cin>>linear[i];
    }
    while(q--){
      int x;cin>>x;
    int ans = binarySearch(linear,1,n,x);
    if(ans>=1)cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
  }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
