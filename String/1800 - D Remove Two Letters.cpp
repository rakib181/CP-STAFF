#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int N = 2e5 + 10;
const int p1 = 137, mod1 = 1e9 + 7, p2 = 277, mod2 = 1e9 + 9;


int power(int n, int k, int mod) {
    int ans = 1;
    while (k) {
        if (k & 1) ans = ans * n % mod;
        n = n * n % mod;
        k >>= 1;
    }
    return ans;
}
int ip1, ip2;
pair<int, int> pw[N]{}, ipw[N]{};
void cal() {
    pw[0] =  {1, 1};
    for (int i = 1; i < N; i++) {
        pw[i].first = pw[i - 1].first * p1 % mod1;
        pw[i].second = pw[i - 1].second * p2 % mod2;
    }
    ip1 = power(p1, mod1 - 2, mod1);
    ip2 = power(p2, mod2 - 2, mod2);
    ipw[0] =  {1, 1};
    for (int i = 1; i < N; i++) {
        ipw[i].first = ipw[i - 1].first * ip1 % mod1;
        ipw[i].second = ipw[i - 1].second * ip2 % mod2;
    }
}

pair<int, int> pref[N]{};
void build(string s) {
    int n = (int) s.size();
    for (int i = 0; i < n; i++) {
        pref[i].first = s[i] * pw[i].first % mod1;
        if (i) pref[i].first = (pref[i].first + pref[i - 1].first) % mod1;
        pref[i].second = s[i] * pw[i].second % mod2;
        if (i) pref[i].second = (pref[i].second + pref[i - 1].second) % mod2;
    }
}
pair<int, int> get_hash(int i, int j) {
    assert(i <= j);
    pair<int, int> hs({0, 0});
    hs.first = pref[j].first;
    if (i) hs.first = (hs.first - pref[i - 1].first + mod1) % mod1;
    hs.first = hs.first * ipw[i].first % mod1;
    hs.second = pref[j].second;
    if (i) hs.second = (hs.second - pref[i - 1].second + mod2) % mod2;
    hs.second = hs.second * ipw[i].second % mod2;
    return hs;
}

pair<int, int> ADD(pair<int, int> x, pair<int, int> y, int i){
    y.first = y.first * pw[i].first % mod1;
    y.first %= mod1;
    y.second = y.second * pw[i].second % mod2;
    y.second %= mod2;
    int xx = x.first + y.first % mod1;
    xx %= mod1;
    int yy = x.second + y.second % mod2;
    yy %= mod2;
    return {xx, yy};
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    int tt;
    cin >> tt;
    while (tt--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        build(s); set<pair<int, int>> st;
        st.insert(get_hash(2, n - 1));
        st.insert(get_hash(0, n - 3));
        for(int i = 1; i + 2 < n; i++){
            pair<int, int> g = ADD(get_hash(0, i - 1), get_hash(i + 2, n - 1), i);
            st.insert(g);
        }
        cout << (int) st.size() << '\n';
    }
    return 0;
}
