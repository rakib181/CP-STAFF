#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), b(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    const long mod = long(1e18 + 9);
    const int base = 1145141;
    vector<long> pw(n + 1);
    pw[0] = 1;
    for(int i = 1; i <= n; i++){
       pw[i] =  long(__int128(pw[i - 1]) * base % mod);
    }
    vector<long> pa(n + 1, 0), pb(n + 1, 0);
    for(int i = 1; i <= n; i++){
        pa[i] = long((__int128(pa[i - 1]) + pw[a[i]]) % mod);
        pb[i] = long((__int128(pb[i - 1]) + pw[b[i]]) % mod);
    }
    auto geta = [&](int l, int r){
        long ans = pa[r];
        ans -= pa[l];
        ans %= mod;
        if(ans < 0) ans += mod;
        return ans;
    };
    auto getb = [&](int l, int r){
        long ans = pb[r];
        ans -= pb[l];
        ans %= mod;
        if(ans < 0)ans += mod;
        return ans;
    };
    while(q--){
        int l, r, L, R;
        cin >> l >> r >> L >> R;
        l--, L--;
        if(geta(l, r) == getb(L, R))cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
