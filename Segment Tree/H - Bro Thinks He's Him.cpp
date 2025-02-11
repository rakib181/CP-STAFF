#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// @author  heisenberg

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

#define long long long
typedef tree<pair<long, long>, null_type, greater<>, rb_tree_tag, tree_order_statistics_node_update> o_set;
const int inf = 1e9 + 7;
const int mod = 998244353;


int power(int x, int y){
    int ans = 1;
    while (y){
        if(y & 1) ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return ans;
}


struct segmentTree{
    vector<int> t;
    void init(int n){
        t.assign(4 * n, 0);
    }
    int merge(int x, int y){
        return int((1LL * x + y) % mod);
    }
    void upd(int node, int b, int e, int i, int v){
        if(b > i or e < i)return;
        if(b == e){
            t[node] = v;
            return;
        }
        int m = (b + e) >> 1;
        upd(2 * node, b, m, i, v);
        upd(2 * node + 1, m + 1, e, i, v);
        t[node] = merge(t[2 * node], t[2 * node + 1]);
    }
    int query(int node, int b, int e, int l, int r){
        if(b > r or e < l)return 0;
        if(b >= l and e <= r){
            return t[node];
        }
        int m = (b + e) >> 1;
        return merge(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
    }
};


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
         int n;
         string s;
         cin >> s;
         n = (int) s.size();
         s = '?' + s;
         segmentTree zeroSeg, oneSeg, sZeroSeg, sOneSeg;
         zeroSeg.init(n);
         oneSeg.init(n);
         sZeroSeg.init(n);
         sOneSeg.init(n);
         int ans = ((power(2, n) - 1) % mod + mod) % mod;
         for(int i = 1; i <= n; i++){
             if(s[i] == '0'){
                 ans += 1LL * oneSeg.query(1, 1, n, 1, i) * power(2, n - i) % mod;
                 ans %= mod;
                 sZeroSeg.upd(1, 1, n, i, power(2, n - i));
                 zeroSeg.upd(1, 1, n, i, power(2, i - 1));
             }else{
                 ans += 1LL * zeroSeg.query(1, 1, n, 1, i) * power(2, n - i) % mod;
                 ans %= mod;
                 sOneSeg.upd(1, 1, n, i, power(2, n - i));
                 oneSeg.upd(1, 1, n, i, power(2, i - 1));
             }
         }
         int q;
         cin >> q;
         while (q--){
            int i;
            cin >> i;
            if(s[i] == '0'){
                int lft = oneSeg.query(1, 1, n, 1, i - 1);
                int rgt = sOneSeg.query(1, 1, n, i + 1, n);
                ans -= 1LL * lft * power(2, n - i) % mod;
                if(ans < 0)ans += mod;
                ans %= mod;
                ans -= 1LL * rgt  * power(2, i - 1) % mod;
                if(ans < 0)ans += mod;
                ans %= mod;
            }else{
                int lft = zeroSeg.query(1, 1, n, 1, i - 1);
                int rgt = sZeroSeg.query(1, 1, n, i + 1, n);
                ans -= 1LL * lft * power(2, n - i) % mod;
                if(ans < 0)ans += mod;
                ans %= mod;
                ans -= 1LL * rgt  * power(2, i - 1) % mod;
                if(ans < 0)ans += mod;
                ans %= mod;
            }
            if(s[i] == '0')s[i] = '1';
            else s[i] = '0';
             if(s[i] == '0'){
                 int lft = oneSeg.query(1, 1, n, 1, i - 1);
                 int rgt = sOneSeg.query(1, 1, n, i + 1, n);
                 ans += 1LL * lft * power(2, n - i) % mod;
                 ans %= mod;
                 ans += 1LL * rgt  * power(2, i - 1) % mod;
                 ans %= mod;
                 oneSeg.upd(1, 1, n, i, 0);
                 sOneSeg.upd(1, 1, n, i, 0);
                 zeroSeg.upd(1, 1, n, i, power(2, i - 1));
                 sZeroSeg.upd(1, 1, n, i, power(2, n - i));
             }else{
                 int lft = zeroSeg.query(1, 1, n, 1, i - 1);
                 int rgt = sZeroSeg.query(1, 1, n, i + 1, n);
                 ans += 1LL * lft * power(2, n - i) % mod;
                 ans %= mod;
                 ans += 1LL * rgt  * power(2, i - 1) % mod;
                 ans %= mod;
                 zeroSeg.upd(1, 1, n, i, 0);
                 sZeroSeg.upd(1, 1, n, i, 0);
                 oneSeg.upd(1, 1, n, i, power(2, i - 1));
                 sOneSeg.upd(1, 1, n, i, power(2, n - i));
             }
             cout << ans << ' ';
         }
         cout << '\n';
    }
    return 0;
}
