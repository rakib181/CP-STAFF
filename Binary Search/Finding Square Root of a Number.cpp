#include<bits/stdc++.h>
using namespace std;

const double eps=1e-5;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    #endif
    auto start=clock();
    double n;
    cin>> n;
    double l=1,r=n;
    while((r-l)>eps){
      double mid=(l+r)/2;
      if(mid*mid<n){
        l=mid;
      }else{
        r=mid;
      }
    }

    cout<< l << '\n' << setprecision(20)<< l << '\n';

    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
