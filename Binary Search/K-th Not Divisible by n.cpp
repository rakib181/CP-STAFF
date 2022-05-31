#include<bits/stdc++.h>
using namespace std;

long long n,k;

bool good1(long long x){
  long long div= x - (x/n);
  return div > k;
}

bool good2(long long x){
  long long div= x - (x/n);
  return div < k;
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
    long long tt;
    cin >> tt;
    while(tt--){
    cin>>n>>k;
    long long l=1,r=1e18;
    while(l<=r){
      long long mid=(l+r)>>1;
      if(good1(mid)){
        r=mid-1;
      }else if(good2(mid)){
        l=mid+1;
      }else{
        if(mid % n != 0){
          cout << mid << '\n';
          break;
        }else{
         r=mid-1;
        }
      }
    }
  }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
