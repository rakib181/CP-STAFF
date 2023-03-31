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

#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 9;
const double eps = 1e-6;
int n, x[N], s[N];
double segment_left[N], segment_right[N];

bool good(double time){
    for(int i = 1; i <= n; i++){
        segment_left[i] = x[i] - time * s[i];
        segment_right[i] = x[i] + time * s[i];
    }
    double MX = 1e40, MN = -1e40;;
    for(int i = 1; i <= n; i++){
        MN = max(MN, segment_left[i]);
    }
    for(int i = 1; i <= n; i++){
        MX = min(MX, segment_right[i]);
    }
    return MX >= MN;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> s[i];
    }
    double l = 0, r = 1e9 + 9, ans = 0;
    while ((r - l) > eps){
        double m  = (l + r) / 2;
        if(good(m)){
            ans = m;
            r = m;
        }else l = m;
    }
    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}
