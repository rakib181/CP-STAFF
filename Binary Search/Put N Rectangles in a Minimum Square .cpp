#include<bits/stdc++.h>
using namespace std;

long long w,h,n;

bool good(long long x){
  return (x/w)*(x/h)>=n;
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
    cin>> w>>h>>n;
    long long l=0,r=1;
    while(!good(r)) r<<=1;
    while(r>l+1){
      long long mid=(l+r)>>1;
      if(good(mid)){
        r=mid;
      }else{
        l=mid;
      }
    } 
    cout << r << '\n';
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
