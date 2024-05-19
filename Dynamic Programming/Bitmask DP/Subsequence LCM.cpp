#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;

int power(int x, int y){
    int ans = 1;
    while(y){
        if(y & 1)ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; ll m;
    cin >> n >> m;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll original = m;
    vector<ll> f;
    if(m % 2 == 0) {
        ll val = 1;
        while (m % 2 == 0) {
             val *= 2;
             m /= 2;
        }
        f.emplace_back(val);
    }
    for(ll i = 3; i * i <= m; i += 2){
        if(m % i == 0){
            ll val = 1;
            while(m % i == 0){
                val *= i;
                m /= i;
            }
            f.emplace_back(val);
        }
    }
    if(m > 1)f.emplace_back(m);
    int sz = 1 << (int) f.size();
    m = original;
    vector<int> cnt(1 << 15, 0);
    for(int i = 0; i < n; i++){
        if(m % a[i])continue;
        int msk = 0;
        for(int j = 0; j < (int) f.size(); j++){
            if(a[i] % f[j] == 0){
                msk |= (1 << j);
            }
        }
        cnt[msk] += 1;
    }
    if(f.empty()){
        cout << (1LL * (power(2, cnt[0]) - 1) % mod + mod) % mod<< '\n';
        return 0;
    }
    vector<int> dp(1 << 15, 0);
    dp[0] = 1;
    for(int msk = 0; msk < sz; msk++){
        int coefficient = ((power(2, cnt[msk]) - 1) % mod + mod) % mod;
        for(int new_msk = sz; new_msk >= 0; new_msk--){
            dp[msk | new_msk] = 1LL * (1LL * dp[msk | new_msk] +  1LL * dp[new_msk] * coefficient % mod) % mod;
        }
    }
    cout << dp[sz - 1] << '\n';
    return 0;
}
