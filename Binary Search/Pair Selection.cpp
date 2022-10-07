#include <bits/stdc++.h>
using  namespace std;

const double eps = 1e-6;

bool feasible(vector<pair<int, int>> &ar, int n, double x, int k){
    vector<double> diff(n);
    for(int i = 0; i < n; i++){
        diff[i] = (double)ar[i].first - (x * (double)ar[i].second);
    }
    sort(diff.rbegin(), diff.rend());
    double sum = 0.0;
    for(int i = 0; i < k; i++){
        sum += diff[i];
    }
    return sum >= 0.0;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<pair<int , int>> ar(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i].first >> ar[i].second;
    }
    double l = 0.0, r = 1e5;
    while((r - l) > eps){
        double mid = (l + r) / 2.0;
        if(feasible(ar, n, mid, k)){
            l = mid;
        }else r = mid;
    }
    cout << fixed << setprecision(6) << r << '\n';
    return 0;
}
