#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=50010;
int ar[N];
ll n, k;

long long binary(long long l,long long r){
  ll mid, maxi=0, cnt;
  while(l<=r){
    mid=(l+r)>>1;
    cnt=0;
    for(int i=0; i<n; i++){
      cnt+= ar[i] / mid;
      if(cnt >= k)break;
    }
    if(cnt>=k){
      l = mid + 1;
      maxi=max(maxi,mid);
    }else{
      r = mid - 1;
    }
  }
  return maxi;
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
    int tt;
    cin >> tt;
    while(tt--){
      cin >> n >> k;
      ll maxi=-1;
      for(int i = 0 ; i < n ; i++){
        cin >> ar[i];
        maxi=max((int)maxi,(int)ar[i]);
      }
     cout << binary(1,maxi) << '\n';
    }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
