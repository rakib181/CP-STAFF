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

const int N = 12;
int dp[N][2][2], n;
string l, r;

int f(int i, int is_smaller, int is_greater){
    if(i == n){
        return 0;
    }
    if(dp[i][is_smaller][is_greater] != -1)return dp[i][is_smaller][is_greater];
    int ans = inf;
    int x = is_greater ? 0 : l[i] - '0';
    int y = is_smaller ? 9 : r[i] - '0';
    if(x == 0 and i == 0)x = 1;
    for(int d = x; d <= y; d++){
        ans = min(ans, f(i + 1, (is_smaller | ((r[i] - '0') > d)), (is_greater | ((l[i] - '0') < d))) + + ((l[i] - '0') == d) + ((r[i] - '0') == d));
    }
    return dp[i][is_smaller][is_greater] = ans;
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        cin >> l >> r;
        n = (int) l.size();
        for(int i = 0; i <= n; i++){
            for(int j = 0; j < 2; j++){
                for(int k = 0; k < 2; k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        cout << f(0, 0, 0) << '\n';
    }
    return 0;
}
