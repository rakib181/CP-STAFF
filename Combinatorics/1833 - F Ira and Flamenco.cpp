#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9, MOD = 1e9 + 7;

int bin(int x, int y){
    int ans = 1;
    while(y){
        if(y & 1)ans = 1LL * ans * x % MOD;
        x = 1LL * x * x % MOD;
        y >>= 1;
    }
    return ans;
}

int inv(int x){
    return bin(x, MOD - 2);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        map<int, int> mp;
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            mp[x] += 1;
        }
        vector<pair<int, int>> a;
        for(auto x : mp){
            a.emplace_back(x);
        }
        int ans = 0, x = 1;
        if(m <= (int) a.size() and a[m - 1].first - a[0].first == m - 1) {
            for (int i = 0; i < m; i++) {
                x = 1LL * x * a[i].second % MOD;
            }
            ans += x;
        }
        for(int i = m; i < (int) a.size(); i++){
            if(a[i].first - a[i - m + 1].first == m - 1) {
                x = 1LL * x * a[i].second % MOD;
                x = 1LL * (1LL * x * inv(a[i - m].second)) % MOD;
                ans = 1LL * (1LL * ans + x) % MOD;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
