#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 9, p1 = 131, p2 = 151, mod1 = 2147483647, mod2 = 999999937;

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


struct ST{
    vector<pair<int, int>> t;
    int n{};
    string s;
    ST()= default;
    ST(int n, string &a){
        this -> n = n;
        this -> s = a;
        t.assign(4 * n, {0, 0});
    }

    static pair<int, int> val(pair<int, int> x, int y){
        return {1LL * x.first * y % mod1, 1LL * x.second * y % mod2};
    }
    static pair<int, int> merge(pair<int, int> x, pair<int, int> y){
        return {(1LL * x.first + y.first) % mod1, (1LL * x.second + y.second) % mod2};
    }
    void build(int node, int b, int e){
        if(b == e){
            t[node] = val(pw[b], s[b]);
            return;
        }
        int m = (b + e) >> 1;
        build(2 * node, b, m);
        build(2 * node + 1, m + 1, e);
        t[node] = merge(t[2 * node], t[2 * node + 1]);
    }
    void upd(int node, int b, int e, int i, char v){
        if(b > i or e < i)return;
        if(b == e){
            t[node] = val(pw[b], v);
            return;
        }
        int m = (b + e) >> 1;
        upd(2 * node, b, m, i, v);
        upd(2 * node + 1, m + 1, e, i, v);
        t[node] = merge(t[2 * node], t[2 * node + 1]);
    }
    pair<int, int> query(int node, int b, int e, int l, int r){
        if(b > r or e < l)return {0, 0};
        if(b >= l and e <= r){
            return t[node];
        }
        int m = (b + e) >> 1;
        return merge(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
    }

    pair<int, int> get_hash(int l, int r){
        auto hs = query(1, 0, n - 1, l, r);
        hs.first = 1LL * hs.first * ipw[l].first % mod1;
        hs.second = 1LL * hs.second * ipw[l].second % mod2;
        return hs;
    }
};


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    ST ori(n, s);
    ori.build(1, 0, n - 1);
    reverse(s.begin(), s.end());
    ST rev(n, s);
    rev.build(1, 0, n - 1);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int i; char c;
            cin >> i >> c;
            i -= 1;
            ori.upd(1, 0, n - 1, i, c);
            rev.upd(1, 0, n - 1, n - i - 1, c);
        }else{
            int l, r;
            cin >> l >> r;
            l -= 1, r -= 1;
            if(ori.get_hash(l, r) == rev.get_hash(n - r - 1, n - l - 1)){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
    }
    return 0;
}