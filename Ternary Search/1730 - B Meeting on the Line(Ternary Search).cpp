#include <bits/stdc++.h>
using namespace std;

double loc(vector<pair<int, int>> &ar, int n, double x){
    double tme, ans = 0.0;
    for(int i = 0; i < n; i++){
        tme = (ar[i].second + abs(ar[i].first - x));
        ans = max<double> (ans, tme);
    }
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
     int n;
     cin >> n;
     vector<pair<int, int>> ar(n);
     for(int  i = 0; i < n; i++){
         cin >> ar[i].first;
     }
     for(int i = 0; i < n; i++){
         cin >> ar[i].second;
     }
     sort(ar.begin(), ar.end()); int it = 60;
     double l = ar[0].first, r = ar[n - 1].first;
     while(it--){
         double mid1 = l + (r - l) / 3.0, mid2 = r - (r - l) / 3.0;
         if(loc(ar, n, mid1) >= loc(ar, n, mid2)){
             l = mid1;
         }else r = mid2;
      }
     cout << fixed << setprecision(6) << r << '\n';
    }
    return 0;
}
