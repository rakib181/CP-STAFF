#include<bits/stdc++.h>
using namespace std;
#define int long long int

int lcm(int a, int b){
    return a * b / __gcd(a, b);
}

int good(int a, int b, int c, int num){
    return ((num / a) + (num / b) + (num / c) - (num / lcm(a, b)) - (num / lcm(b, c)) - (num / lcm(a, c)) + (num / lcm(a , lcm(b, c))));
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
       int n, a, b, c;
       cin >> n >> a >> b >> c;
       int l = 1, r = max({a, b, c}) * n, ans = 0;
        while (l <= r){
            int mid = (l + r) / 2;
            int ini = good(a, b, c, mid);
            if(ini < n){
                l = mid + 1;
            }else if(ini == n){
                ans = mid;
                r = mid - 1;
            }else r = mid - 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
