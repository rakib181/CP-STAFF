#include<bits/stdc++.h>
using namespace std;
int n,x,y;
bool good(int m){
 return (m/x)+(m/y)>=n-1;
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
    cin >> n >> x >> y;
    if(n==1){
      cout<<min(x,y)<<'\n';
      return 0;
    }
    int l=0,r=1e9;
    while(r>l+1){
      int mid=(l+r)>>1;
      if(good(mid)){
        r=mid;
      }else{
        l=mid;
      }
    }
    cout<< r+min(x,y) << '\n'; 
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
