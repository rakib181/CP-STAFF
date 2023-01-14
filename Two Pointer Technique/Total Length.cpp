#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int l = 0, r = 0, sum = 0, ans = 0;
    while (r < n){
        if(sum + a[r] <= s){
            sum += a[r];
        }else{
            while (sum + a[r] > s){
                sum -= a[l++];
            }
            sum += a[r];
        }
        ans += (((r - l + 1) * (r - l + 2)) / 2);
        r++;
    }
    cout << ans << '\n';
    return 0;
}
