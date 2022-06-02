#include<bits/stdc++.h>
using namespace std;

const int x=2e5+10;
int n,m,a[x],b[x];
bool ok;

void letsTry(int x){
   m=0;
  for(int i=0;i<n;i++){
    if(a[i]!=x){
       b[m++]=a[i];
    }
  }
  for(int i=0;i<m;i++){
    if(b[i]!=b[m-i-1]){
      return;
    }
  }
  ok=true;
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
      cin >> n;
      for(int i=0;i<n;i++){
        cin >> a[i];
      }
      ok=true;
      for(int i=0;i<n;i++){
        if(a[i] !=a[n-i-1]){
          ok=false;
          letsTry(a[i]);
          letsTry(a[n-i-1]);
          break;
        }
      }
      if(ok){
        cout << "YES\n";
      }else{
        cout << "NO\n";
      }
    }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
