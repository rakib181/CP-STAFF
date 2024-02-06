#include<bits/stdc++.h>
using namespace std;
using ll = long long;

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

struct node{
    int l, r;
};

pair<int, int> prefix[N];

void build(string &s){
    int n = (int) s.size();
    for(int i = 0; i < n; i++){
        prefix[i].first = 1LL * s[i] * pw[i].first % mod1;
        if(i) prefix[i].first = 1LL * (1LL * prefix[i].first + prefix[i - 1].first) % mod1;
        prefix[i].second = 1LL * s[i] * pw[i].second % mod2;
        if(i) prefix[i].second = 1LL * (1LL * prefix[i].second + prefix[i - 1].second) % mod2;
    }
}

pair<int, int> get_hash(int l, int r){
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

pair<int, int> string_hash(string &s){
    int n = (int) s.size();
    pair<int, int> hs({0, 0});
    for(int i = 0; i < n; i++){
        hs.first = 1LL * (1LL * hs.first + 1LL * s[i] * pw[i].first % mod1) % mod1;
        hs.second = 1LL * (1LL * hs.second + 1LL * s[i] * pw[i].second % mod2) % mod2;
    }
    return hs;
}


int lcp(int i, int j, int x, int y){
    int l = 1, r = min(j - i + 1, y - x + 1), id = 0;
    while(l <= r){
        int m = (l + r) >> 1;
        if(get_hash(i, i + m - 1) == get_hash(x, x + m - 1)){
            id = m;
            l = m + 1;
        }else{
            r = m - 1;
        }
    }
    return id;
}

string s;
int compare(int i, int j, int x, int y){
    int lc = lcp(i, j, x, y);
    int len1 = j - i + 1, len2 = y - x + 1;
    if(len1 == len2 and len1 == lc)return 0; // equal
    if(len1 == lc)return -1;  // 1st one is smaller
    if(len2 == lc)return 1;   // 2nd one is smaller
    return s[i + lc] < s[x + lc] ? -1 : 1;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    cin >> s;
    int n = (int) s.size();
    build(s);
    vector<node> a;
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        l -= 1, r -= 1;
        a.push_back({l, r});
    }
    sort(a.begin(), a.end(), [&](node &x, node &y){
        int cmp = compare(x.l, x.r, y.l, y.r);
        if(cmp != 0){
            return cmp == -1;
        }
        if(x.l != y.l){
            return x.l < y.l;
        }
        return x.r < y.r;
    });
    for(auto [l, r] : a){
        cout << l + 1 << ' ' << r + 1 << '\n';
    }
    return 0;
}