#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 6e5 + 9, mod = 998244353;
int f[N], inv[N];

int power(int x, int y){
    int ans = 1;
    while(y){
        if(y & 1) ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return ans;
}

int inverse(int n){
    return power(n, mod - 2);
}

void cal(){
    f[0] = 1;
    for(int i = 1; i < N; i++){
        f[i] = 1LL * f[i - 1] * i % mod;
    }
    inv[N - 1] = inverse(f[N - 1]);
    for(int i = N - 2; i >= 0; i--){
        inv[i] = 1LL * inv[i + 1] * (i + 1) % mod;
    }
}

int nCr(int n, int r){
    if(r > n or n < 0)return 0;
    return 1LL * f[n] * inv[r] % mod * inv[n - r] % mod;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cal();
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n + 1);
    set<int> se;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
        se.insert(a[i].first);
        se.insert(a[i].second);
    }
    map<int, int> mp;
    int id = 0;
    for(auto x : se){
        mp[x] = ++id;
    }
    for(int i = 1; i <= n; i++){
        a[i] = {mp[a[i].first], mp[a[i].second]};
    }
    vector<int> d(id + 2, 0);
    vector<int> st(id + 2, 0);
    for(int i = 1; i <= n; i++){
        st[a[i].first] += 1;
        d[a[i].first] += 1;
        d[a[i].second + 1] -= 1;
    }
    for(int i = 1; i <= id; i++){
        d[i] += d[i - 1];
    }
    int ans = 0;
    for(int i = 1; i <= id; i++){
         int x = d[i];
         int y = st[i];
         int val = nCr(x, k) - nCr(x - y, k);
         val %= mod;
         if(val < 0) val += mod;
         ans += val;
         ans %= mod;
    }
    cout << ans << '\n';
    return 0;
}