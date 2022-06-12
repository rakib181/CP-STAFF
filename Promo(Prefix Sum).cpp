#include<bits/stdc++.h>
using namespace std;

#define ll long long

int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    #endif
    auto start=clock();
    ll n, q;
    cin >> n >> q;
    ll a[n+1];
    for(ll i=1;i<=n;i++)cin >> a[i];
      sort(a+1,a+n+1);
    ll pre_sum[n+10];
    pre_sum[0]=a[1];
    for(ll i=1;i<=n;i++){
    pre_sum[i] = pre_sum[i-1] + a[i];
  }  
      while(q--){
        ll x, y;
        cin >> x >> y;
        cout << pre_sum[n-x+y]-pre_sum[n-x]<< '\n';
    }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
