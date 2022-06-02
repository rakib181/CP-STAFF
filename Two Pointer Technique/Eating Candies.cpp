#include<bits/stdc++.h>
using namespace std;

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
      int n;
      cin >> n;
      vector<int> v(n+1);
      for(int i=0;i<n;i++){
        cin >> v[i];
      }
      int ans=0,i=0,j=n-1,suma=v[0],sumb=v[n-1];
      while(i<j){
        if(suma==sumb){
          ans=max(ans,i+1+n-j);
        }
        if(suma<=sumb){
          suma+=v[++i];
        }else{
          sumb+=v[--j];
        }
      }
      cout << ans << '\n';
    }

    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
