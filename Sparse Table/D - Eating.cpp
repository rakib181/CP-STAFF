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


struct ST{
    vector<vector<int>> t;
    vector<int> a;
    int lg = 25;
    ST() = default;
    explicit ST(int n, vector<int> b){
        this -> t.assign(lg, vector<int> (n + 10, 0));
        this -> a.assign(n + 2, 0);
        for(int i = 1; i <= n; i++){
            this -> a[i] = b[i];
        }
    }
    void build(int n){
        for(int i = 1; i <= n; i++){
            t[1][i] = a[i];
        }
        for(int i = 1; i < lg; i++){
            for(int j = 1; j + (1 << (i - 1)) <= n; j++){
                t[i + 1][j] = max(t[i][j], t[i][j + (1 << (i - 1))]);
            }
        }
    }
    int query(int l, int r){
        int _lg = __lg(r - l + 1) + 1;
        return max(t[_lg][l], t[_lg][r - (1 << (_lg - 1)) + 1]);
    }
};

int msb(int x){
    return 32 - __builtin_clz(x) - 1;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1, 0), p(n + 1, 0), b(n + 1, 0);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        reverse(a.begin() + 1, a.end());
        for(int i = 1; i <= n; i++){
            p[i] = p[i - 1] ^ a[i];
        }
        for(int i = 1; i <= n; i++){
            b[i] = msb(a[i]);
        }
        auto get = [&](int l, int r){
            return p[r] ^ p[l - 1];
        };
        ST st(n, b);
        st.build(n);
        while (q--){
            int x;
            cin >> x;
            int ans = 0, id = 0;
            while (true){
                int l = id + 1, r = n, f = -1;
                while (l <= r){
                    int m = (l + r) >> 1;
                    if(st.query(id + 1, m) < msb(x)){
                        f = m;
                        l = m + 1;
                    }else{
                        r = m - 1;
                    }
                }
                if(f != -1){
                    x ^= get(id + 1, f);
                    ans = f;
                    id = f;
                }
                if(id + 1 > n or a[id + 1] > x)break;
                id++;
                x ^= a[id];
                ans++;
                if(id == n or x == 0)break;
            }
            cout << ans << ' ';
        }
        cout << '\n';
    }
    return 0;
}
