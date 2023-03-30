// x^2 + sqrt(x) = c

#include<bits/stdc++.h>
using namespace std;

const double eps=1e-6;
double c;

double binary(double x){
  double l=1,r=1e6;
  while((r-l)>eps){
     double mid=(l+r)/2;
     if(mid*mid>x){
      r=mid;
     }else{
      l=mid;
     }
  }
  return l;
}

bool good(double x){
  double temp=x*x+ binary(x);
  if(temp > c)return true;
  else return false;
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
    cin>>c;
    double l=1,r=1e10;
    for(int i=0;i<60;i++){
      double mid=(l+r)/2;
      if(good(mid)){
        r=mid;
      }else{
        l=mid;
      }
    }
    cout << setprecision(15) << r <<'\n';
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long int
const double eps = 1e-6; double c;

double SQRT(double x){
    double l = 1, r = x / 2 + 1.0;
    while ((r - l) > eps){
        double m = (l + r) / 2;
        if(m * m >= x){
            r = m;
        }else l = m;
    }
    return r;
}

bool good(double x){
    return (x * x) + SQRT(x) >= c;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c;
    double l = 1, r = 1e5, ans = 0;
    while ((r - l) > eps){
        double m = (l + r) / 2;
        if(good(m)){
            ans = m;
            r = m;
        }else l = m;
    }
    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}
