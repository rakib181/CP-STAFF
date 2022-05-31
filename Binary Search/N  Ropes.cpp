#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<int> v;

bool good(double x){
  int check=0;
  for(int i=0;i<n;i++){
      check += v[i]/x;
  }
  return check >= k;
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
    cin>>n>>k;
    v.resize(n);
    for(int i=0;i<n;i++) cin>>v[i];
    double l=0,r=1e8;
    for(int i=0;i<60;i++){
    double mid=(l+r)/2;
    if(good(mid)){
      l=mid;
    }else{
      r=mid;
    }
  }
  cout << setprecision(10) << r << '\n';
  cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
  return 0;
}
