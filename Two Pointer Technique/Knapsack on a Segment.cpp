#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s;
    cin >> n >> s;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
    }
    for(int i = 0; i < n; i++){
        cin >> a[i].second;
    }
    vector<int> prefix(n + 1, 0);
    prefix[0] = a[0].second;
    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i - 1] + a[i].second;
    }
    int l = 0, r = 0, sum = 0, ans = 0;
    while (r < n){
        if(sum + a[r].first <= s){
            sum += a[r].first;
        }else{
            while (sum + a[r].first > s){
                sum -= a[l++].first;
            }
            sum += a[r].first;
        }
      if(l > 0) ans = max(ans, prefix[r] - prefix[l - 1]);
      else ans = max(ans, prefix[r]);
       r++;
    }
    cout << ans << '\n';
    return 0;
}
