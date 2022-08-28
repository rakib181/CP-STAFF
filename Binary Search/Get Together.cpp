#include <bits/stdc++.h>
using namespace std;

bool good(vector<pair<double, double>> ar, int n, double time){
      auto left = (double) INT_MIN, right = (double) INT_MAX;
      for(int i = 0; i < n; i++){
          left = max(left, ar[i].first - ar[i].second * time);
          right = min(right, ar[i].first + ar[i].second * time);
      }
      return right - left >= 0;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<double, double>> ar(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i].first >> ar[i].second;
    }
    double l = 0, r = 2 * 1e9;
    for(int i = 0; i < 60; i++){
        double mid = (l + r) / 2;
        if(good(ar, n, mid)){
            r = mid;
        }else l = mid;
    }
    cout << setprecision(15) << r << '\n';
    return 0;
}
