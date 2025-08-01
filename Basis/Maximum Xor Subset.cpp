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
    vector<int> b;
    explicit basis(){
        b.assign(B, 0);
    }
    void add(int x){
        for(int bit = B - 1; bit >= 0; bit--){
            if(x >> bit & 1){
                if(b[bit]){
                    x ^= b[bit];
                }else {
                    b[bit] = x;
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
    int n;
    cin >> n;
    basis b;
    for(int i = 0; i < n; i++){
       int x;
       cin >> x;
       b.add(x);
    }
    cout << b.max_xor_subset();
    return 0;
}
