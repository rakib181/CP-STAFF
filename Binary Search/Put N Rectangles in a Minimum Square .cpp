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
#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int w, h, n;
    cin >> w >> h >> n;

    auto good = [&] (int m){
        int a = m / w;
        int b = m / h;
        return a >= (double) n / b;
    };
    int l = 1, r = 1e14, ans = 0;
    while (l <= r){
        int m = l + (r - l) / 2;
        if(good(m)){
            ans = m;
            r = m - 1;
        }else l = m + 1;
    }
    cout << ans << '\n';
    return 0;
}
