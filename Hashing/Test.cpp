#include <bits/stdc++.h>
using namespace std;
#define long long long
const int N = 4e5 + 9, p1 = 131, p2 = 151, mod1 = 2147483647, mod2 = 999999937;

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

struct hashing{
    vector<pair<int, int>> prefix;
    void build(string &s){
        int n = (int) s.size();
        prefix.assign(n + 1, {0, 0});
        for(int i = 0; i < n; i++){
            prefix[i].first = 1LL * s[i] * pw[i].first % mod1;
            if(i) prefix[i].first = 1LL * (1LL * prefix[i].first + prefix[i - 1].first) % mod1;
            prefix[i].second = 1LL * s[i] * pw[i].second % mod2;
            if(i) prefix[i].second = 1LL * (1LL * prefix[i].second + prefix[i - 1].second) % mod2;
        }
    }

    pair<int, int> get_hash(int l, int r){
        if(l > r)return {0, 0};
        pair<int, int> ans({0, 0});
        ans.first = prefix[r].first;
        if(l){
            ans.first = 1LL * ((1LL * ans.first - prefix[l - 1].first) % mod1 + mod1) % mod1;
            ans.first = 1LL * ans.first * ipw[l].first % mod1;
        }
        ans.second = prefix[r].second;
        if(l){
            ans.second = 1LL * ((1LL * ans.second - prefix[l - 1].second) % mod2 + mod2) % mod2;
            ans.second = 1LL * ans.second * ipw[l].second % mod2;
        }
        return ans;
    }
}h1, h2;

string compress(string a, string b){
    int n = (int) a.size();
    int m = (int) b.size();
    h1.build(a);
    h2.build(b);
    if(n >= m){
        for(int i = 0; i + m - 1 < n; i++){
            if(h1.get_hash(i, i + m - 1) == h2.get_hash(0, m - 1)){
                return a;
            }
        }
    }else{
        for(int i = 0; i + n - 1 < m; i++){
            if(h1.get_hash(0, n - 1) == h2.get_hash(i, i + n - 1)){
                return b;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(h1.get_hash(i, n - 1) == h2.get_hash(0, min(m - 1, n - i - 1))){
             ans = n - i;
             break;
        }
    }
    for(int i = ans; i < m; i++){
        a += b[i];
    }
    return a;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    vector<string> a(3);
    for(int i = 0; i < 3; i++)cin >> a[i];
    vector<int> p(3);
    int sz = 1e9 + 9;
    iota(p.begin(), p.end(), 0);
    do{
        string ans;
        ans = compress(a[p[0]], a[p[1]]);
        ans = compress(ans, a[p[2]]);
        sz = min(sz, (int) ans.size());
        ans.clear();
        ans = compress(a[p[0]], a[p[1]]);
        ans = compress(a[p[2]], ans);
        sz = min(sz, (int) ans.size());
    }while (next_permutation(p.begin(), p.end()));
    cout << sz;
    return 0;
}
