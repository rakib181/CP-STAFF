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

const int N = 5e5 + 9, p1 = 131, p2 = 151, mod1 = 2147483647, mod2 = 999999937;

int power(int x, int y, int mod){
    int ans = 1;
    while(y){
        if(y & 1) ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return ans;
}

int inv(int x, int mod){
    return power(x, mod - 2, mod);
}
pair<int, int> pw[N], ipw[N];

void cal(){
    pw[0] = {1, 1};
    for(int i = 1; i < N; i++){
        pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
    }
    ipw[0] = {1, 1};
    int ip1 = inv(p1, mod1);
    int ip2 = inv(p2, mod2);
    for(int i = 1; i < N; i++){
        ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
        ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
    }
}

struct HASH {
    pair<int, int> prefix[N];
    string s; int n{};
    void build(string &a) {
        this -> s = a;
        this -> n = (int) s.size();
        for (int i = 0; i < n; i++) {
            prefix[i].first = 1LL * s[i] * pw[i].first % mod1;
            if (i) prefix[i].first = 1LL * (1LL * prefix[i].first + prefix[i - 1].first) % mod1;
            prefix[i].second = 1LL * s[i] * pw[i].second % mod2;
            if (i) prefix[i].second = 1LL * (1LL * prefix[i].second + prefix[i - 1].second) % mod2;
        }
    }

    pair<int, int> get_hash(int l, int r) {
        pair<int, int> ans({0, 0});
        if(l > r)return ans;
        ans.first = prefix[r].first;
        if (l) {
            ans.first = 1LL * ((1LL * ans.first - prefix[l - 1].first) % mod1 + mod1) % mod1;
            ans.first = 1LL * ans.first * ipw[l].first % mod1;
        }
        ans.second = prefix[r].second;
        if (l) {
            ans.second = 1LL * ((1LL * ans.second - prefix[l - 1].second) % mod2 + mod2) % mod2;
            ans.second = 1LL * ans.second * ipw[l].second % mod2;
        }
        return ans;
    }

    pair<int, int> change(int id, char c){
        auto ans = get_hash(0, id - 1);
        auto right = get_hash(id + 1, n - 1);
        if(id + 1 < n){
            right.first = 1LL * right.first * pw[id + 1].first % mod1;
            right.second = 1LL * right.second * pw[id + 1].second % mod2;
        }
        ans.first = 1LL * (1LL * ans.first + 1LL * c * pw[id].first % mod1) % mod1;
        ans.second = 1LL * (1LL * ans.second + 1LL * c * pw[id].second % mod2) % mod2;
        ans.first = 1LL * (1LL * ans.first + right.first) % mod1;
        ans.second = 1LL * (1LL * ans.second + right.second) % mod2;
        return ans;
    }
    pair<int, int> del(int id){
        auto ans = get_hash(0, id - 1);
        auto right = get_hash(id + 1, n - 1);
        right.first = 1LL * right.first * pw[id].first % mod1;
        right.second = 1LL * right.second * pw[id].second % mod2;
        ans.first = 1LL * (1LL * ans.first + right.first) % mod1;
        ans.second = 1LL * (1LL * ans.second + right.second) % mod2;
        return ans;
    }

    pair<int, int> insert(int id, char c){
        auto ans = get_hash(0, id - 1);
        auto right = get_hash(id, n - 1);
        ans.first = 1LL * (1LL * ans.first + 1LL * c * pw[id].first % mod1) % mod1;
        ans.second = 1LL * (1LL * ans.second + 1LL * c * pw[id].second % mod2) % mod2;
        if(id + 1 <= n){
            right.first = 1LL * right.first * pw[id + 1].first % mod1;
            right.second = 1LL * right.second * pw[id + 1].second % mod2;
        }
        ans.first = 1LL * (1LL * ans.first + right.first) % mod1;
        ans.second = 1LL * (1LL * ans.second + right.second) % mod2;
        return ans;
    }
}a, b;


static pair<int, int> string_hash(string &s) {
    int n = (int) s.size();
    pair<int, int> hs({0, 0});
    for (int i = 0; i < n; i++) {
        hs.first = 1LL * (1LL * hs.first + 1LL * s[i] * pw[i].first % mod1) % mod1;
        hs.second = 1LL * (1LL * hs.second + 1LL * s[i] * pw[i].second % mod2) % mod2;
    }
    return hs;
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    string s, t;
    cin >> s >> t;
    cal();
    int n = (int) s.size(), m = (int) t.size();
    a.build(s);
    b.build(t);
    if(s == t){
        cout << "Yes\n";
        return 0;
    }
    if(abs(n - m) > 1){
        cout << "No\n";
        return 0;
    }
    auto val = a.get_hash(0, n - 1);
    for(int i = 0; i < m; i++){
        auto x = b.del(i);
        if(val == x){
            cout << "Yes\n";
            return 0;
        }
        for(char c = 'a'; c <= 'z'; c++){
            x = b.change(i, c);
            if(val == x){
                cout << "Yes\n";
                return 0;
            }
        }
    }
    for(int i = 0; i <= m; i++){
        for(char c = 'a'; c <= 'z'; c++) {
            auto x = b.insert(i, c);
            if(x == val){
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
    return 0;
}
