#include<bits/stdc++.h>
using namespace std;

const int N = 6e5 + 9, p1 = 131, p2 = 151, mod1 = 2147483647, mod2 = 999999937;

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

    pair<int, int> merge(int id, char c){
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

    int lcp(int i, int j, int x, int y) {
        int l = 1, r = min(j - i + 1, y - x + 1), id = 0;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (get_hash(i, i + m - 1) == get_hash(x, x + m - 1)) {
                id = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return id;
    }
    int compare(int i, int j, int x, int y){
        int lc = lcp(i, j, x, y);
        int len1 = j - i + 1, len2 = y - x + 1;
        if(len1 == len2 and len1 == lc)return 0; // equal
        if(len1 == lc)return -1;  // 1st one is smaller
        if(len2 == lc)return 1;   // 2nd one is smaller
        return s[i + lc] < s[x + lc] ? -1 : 1;
    }
}hashing;


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
    cal();
    int n, q;
    cin >> n >> q;
    set<pair<int, int>> se;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        hashing.build(s);
        for(int id = 0; id < (int) s.size(); id++){
            if(s[id] == 'a'){
                se.insert(hashing.merge(id, 'b'));
                se.insert(hashing.merge(id, 'c'));
            }else if(s[id] == 'b'){
                se.insert(hashing.merge(id, 'a'));
                se.insert(hashing.merge(id, 'c'));
            }else{
                se.insert(hashing.merge(id, 'a'));
                se.insert(hashing.merge(id, 'b'));
            }
        }
    }
    while(q--){
        string s;
        cin >> s;
        if(se.count(string_hash(s))){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}