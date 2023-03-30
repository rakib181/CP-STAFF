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

#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x, y;
    cin >> n >> x >> y;
    auto good = [&](int m){
        return (m / x) + (m / y) >= (n - 1);
    };
    if(n == 1){
        cout << min(x, y) << '\n';
        return 0;
    }
    int l = 1, r = n * max(x, y), ans = 0;
    while (l <= r){
        int m = (l + r) >> 1;
        if(good(m)){
            ans = m;
            r = m - 1;
        }else l = m + 1;
    }
    cout << ans + min(x, y) << '\n';
    return 0;
}
