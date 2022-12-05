#include<bits/stdc++.h>
using namespace std;

#define int long long int

vector<int> sumsub(vector<int> a){
    int n = a.size();
    vector<int> res;
    for(int i = 0; i < (1 << n); i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            if((i >> j) & 1) sum += a[j];
        }
        res.push_back(sum);
    }
    return res;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a;
    cin >> n >> a;
    vector<int> v(n);
    for(int i = 0; i < n ; i++){
        cin >> v[i];
    }
    vector<int> left, right;
    for(int i = 0; i < n; i++){
        if(i <= n / 2)left.push_back(v[i]);
        else right.push_back(v[i]);
    }

    vector<int> sum_left = sumsub(left);
    vector<int> sum_right = sumsub(right);

    sort(sum_right.begin(), sum_right.end());

    int ans = 0;

    for(auto x : sum_left){
        int sum = x;
        int need = a - sum;
        ans += upper_bound(sum_right.begin(), sum_right.end(), need) -
               lower_bound(sum_right.begin(), sum_right.end(), need);
    }
    cout << ans;
    return 0;
}
