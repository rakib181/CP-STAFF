#include<bits/stdc++.h>
using namespace std;
#define int long long int

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        int n;
        cin >> n;
        vector<int> a(n + 1), prefix(n + 2, 0);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            prefix[i] = prefix[i - 1] + a[i];
        }
        int ans = 0;
        for(int i = 1; i + 1 <= n; i++){
            int x = prefix[i], y = prefix[n] - prefix[i];
            ans = max(ans, gcd(x, y));
        }
        cout << ans << '\n';
    }
    return 0;
}
