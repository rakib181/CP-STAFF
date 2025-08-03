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
const int mod = 1e9 + 7;

struct basis{
    const int B = 32;
    int sz = 0;
    vector<int> b;
    explicit basis(){
        this->b.assign(B, 0);
        this->sz = 0;
    }
    void add(int x){
        for(int bit = B - 1; bit >= 0; bit--){
            if(x >> bit & 1){
                if(b[bit]){
                    x ^= b[bit];
                }else {
                    b[bit] = x;
                    sz++;
                    break;
                }
            }
        }
    }

    bool can(int x){
        for(int bit = B - 1; bit >= 0; bit--){
            x = min(x, x ^ b[bit]);
        }
        return x == 0;
    }

    int max_xor_subset(){
        int ans = 0;
        for(int bit = B - 1; bit >= 0; bit--){
            ans = max(ans, ans ^ b[bit]);
        }
        return ans;
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int> pw(n + 1, 0);
    pw[0] = 1;
    for(int i = 1; i <= n; i++){
        pw[i] = 1LL * pw[i - 1] * 2 % mod;
    }
    vector<pair<int, int>> query[n + 1];
    for(int i = 1; i <= q; i++){
        int l, x;
        cin >> l >> x;
        query[l].emplace_back(x, i);
    }
    basis bs;
    vector<int> ans(q + 1, 0);
    for(int l = 1; l <= n; l++){
        bs.add(a[l]);
        for(auto [x, i] : query[l]){
            if(bs.can(x)){
                ans[i] = pw[l - bs.sz];
            }
        }
    }
    for(int i = 1; i <= q; i++){
        cout << ans[i] << '\n';
    }
    return 0;
}
