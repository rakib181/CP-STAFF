#include<bits/stdc++.h>
using namespace  std;
using ll = long long;
const int N = 5e5 + 9, p1 = 11617, p2 = 11701, mod1 = 1e9 + 7, mod2 = 1e9 + 9;
int spf[N], a[N];

pair<int, int> pw[N], ipw[N];

int bin(int x, int y, int mod){
    int ans = 1;
    while(y){
        if(y & 1)ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return ans;
}

void pre(){
    pw[0] = {1, 1};
    ipw[0] = {1, 1};
    for(int i = 1; i < N; i++){
        pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
    }
    int ip1 = bin(p1, mod1 - 2, mod1);
    int ip2 = bin(p2, mod2 - 2, mod2);
    for(int i = 1; i < N; i++){
        ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
        ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
    }
}

struct Hashing{
    vector<int> s;
    int n;
    vector<pair<int, int>> hs;
    explicit Hashing(vector<int> &s){
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

void cal(){
    for(int i = 1; i < N; i++)spf[i] = i;
    for(int i = 2; i < N; i++){
        if(spf[i] == i){
            for(int j = i + i; j < N; j += i){
                spf[j] = min(spf[j], i);
            }
        }
    }
}
set<int> se;
vector<int> factorize(int x){
    vector<int> p;
    while(x > 1){
        int pr = spf[x];
        while(x % pr == 0){
            p.emplace_back(pr);
            x /= pr;
        }
    }
    return p;
}
int pr_pw[N];
void upd(int v, int k){
    vector<int> f = factorize(v);
    for(auto x : f){
        if(pr_pw[x] % 2 == 1){
            se.erase(x);
        }
        pr_pw[x] += k;
        if(pr_pw[x] % 2 == 1){
            se.insert(x);
        }
    }
}

bool check(){
    return se.empty();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    pre();
    cal();
    int n, k;
    cin >> n >> k; vector<int> v;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        v.emplace_back(a[i]);
    }
    Hashing hashing(v);
    set<pair<int, int>> ans;
    for(int i = 1; i <= n; i++){
        upd(a[i], +1);
        if(i > k){
            upd(a[i - k], -1);
        }
        if(i >= k){
            if(check()){
                int l = i - k + 1, r = i;
                ans.insert(hashing.get_hash(l, r));
            }
        }
    }
    cout << (int) ans.size() << '\n';
    return 0;
}
