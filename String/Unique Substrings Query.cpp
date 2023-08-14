#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 9, p1 = 131, p2 = 277, mod1 = 1e9 + 7, mod2 = 1e9 + 9;
pair<int, int> pw[N], ipw[N];

int bin(int x, int y, int m){
    int ans = 1;
    while (y){
        if(y & 1) ans = 1LL * ans * x % m;
        x = 1LL * x * x % m;
        y >>= 1;
    }
    return ans;
}

void cal(){
    pw[0] = {1, 1};
    for(int i = 1; i < N; i++){
        pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
    }
    int ip1 = bin(p1, mod1 - 2, mod1);
    int ip2 = bin(p2, mod2 - 2, mod2);
    ipw[0] = {1, 1};
    for(int i = 1; i < N; i++){
        ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
        ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
    }
}

struct hashing{
    int n;
    string s;
    vector<pair<int, int>> hs;
    explicit hashing(string &s){
        this -> n = (int) s.size();
        this -> s = s;
        hs.emplace_back(0, 0);
        for(int i = 0; i < n; i++){
            pair<int, int> p;
            p.first = 1LL * (1LL * hs[i].first + 1LL * pw[i].first * s[i] % mod1) % mod1;
            p.second = 1LL * (1LL * hs[i].second + 1LL * pw[i].second * s[i] % mod2) % mod2;
            hs.emplace_back(p);
        }
    }
    pair<int, int> get_hash(int l, int r){
        pair<int, int> ans;
        ans.first = 1LL * (1LL * hs[r].first - hs[l - 1].first + mod1) * 1LL * ipw[l - 1].first % mod1;
        ans.second = 1LL * (1LL * hs[r].second - hs[l - 1].second + mod2) * 1LL * ipw[l - 1].second % mod2;
        return ans;
    }
};
ll f[N][N];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    hashing H(s);
    for(int len = 1; len <= n; len++){
        set<pair<int, int>> se;
        for(int i = n; i >= 1; i--){
            if(i + len - 1 <= n){
                se.insert(H.get_hash(i, i + len - 1));
            }
            f[i][len] = (int) se.size();
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
        }
    }
    while (q--){
        int x1, y1, x2, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        cout << f[x2][y2] - f[x2][y1 - 1] - f[x1 - 1][y2] + f[x1 - 1][y1 - 1] << '\n';
    }
    return 0;
}
