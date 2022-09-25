#include<bits/stdc++.h>
using namespace std;

double eps = 1e-6;

double go_left(vector<pair<double, double>> &pos, int n, double mid){
    double ans = 0.0;
    for(int i = 0; i < n; i++){
        if(mid > pos[i].first) ans = max<double>(ans, (mid - pos[i].first) + pos[i].second);
        else break;
    }
    return ans;
}

double go_right(vector<pair<double,double>> &pos, int n, double mid){
    double ans = 0.0;
    for(int i = n - 1; i >= 0; i--){
      if(mid <= pos[i].first) ans = max<double>(ans, (pos[i].first - mid) + pos[i].second);
      else break;
    }
    return ans;
}

int32_t main(){
     ios_base::sync_with_stdio(0);
      cin.tie(0); 
      int tt;
      cin >> tt;
      while(tt--){
        int n;
        cin >> n;
        vector<pair<double, double>> pos(n);
        for(int i = 0; i < n; i++){
            cin >> pos[i].first;
        }
        for(int i = 0; i < n; i++){
            cin >> pos[i].second;
        }
        sort(pos.begin(), pos.end());
        double l = pos[0].first, r = pos[n - 1].first;
        while((r - l) > eps){
            double mid = (l + r) / 2.0;
            double left_part = go_left(pos, n, mid);
            double right_part = go_right(pos, n, mid);
            if(left_part > right_part){
                r = mid;
            }else{
                l = mid;
            }
        }
        cout << fixed << setprecision(6) << r << '\n';
      }
      return 0;
}
