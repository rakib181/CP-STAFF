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

#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 9; double eps = 1e-6;
double a[N];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    auto good = [&](double m){
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            cnt += a[i] / m;
        }
        return cnt >= k;
    };
    double l = 0.0, r = accumulate(a + 1, a + n + 1, 0.0);
    while((r - l) > eps){
        double m = (l + r) / 2.0;
        if(good(m)){
            l = m;
        }else r = m;
    }
    cout << fixed << setprecision(10) << r << '\n';
    return 0;
}
