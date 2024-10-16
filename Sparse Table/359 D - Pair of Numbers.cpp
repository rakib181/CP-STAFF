#include<bits/stdc++.h>
using namespace std;
#define long long long

const int inf = 1e9 + 7;

struct MIN{
    vector<vector<int>> t;
    vector<int> a;
    int lg = 25;
    MIN() = default;
    explicit MIN(int n, vector<int> b){
        this -> t.assign(lg, vector<int> (n + 10, inf));
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
                t[i + 1][j] = min(t[i][j], t[i][j + (1 << (i - 1))]);
            }
        }
    }
    long query(int l, int r){
        int _lg = __lg(r - l + 1) + 1;
        return min(t[_lg][l], t[_lg][r - (1 << (_lg - 1)) + 1]);
    }
};

struct GCD{
    vector<vector<int>> t;
    vector<int> a;
    int lg = 25;
    GCD() = default;
    explicit GCD(int n, vector<int> b){
        this -> t.assign(lg, vector<int> (n + 10, inf));
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
                t[i + 1][j] = __gcd(t[i][j], t[i][j + (1 << (i - 1))]);
            }
        }
    }
    long query(int l, int r){
        int _lg = __lg(r - l + 1) + 1;
        return __gcd(t[_lg][l], t[_lg][r - (1 << (_lg - 1)) + 1]);
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)cin >> a[i];
    GCD gc(n, a);
    MIN mn(n, a);
    gc.build(n);
    mn.build(n);
    auto f = [&](int len){
        for(int i = 1; i + len - 1 <= n; i++){
            if(mn.query(i, i + len - 1) == gc.query(i, i + len - 1))return true;
        }
        return false;
    };
    int l = 1, r = n, ans = 0;
    while (l <= r){
        int m = (l + r) >> 1;
        if(f(m)){
            ans = m;
            l = m + 1;
        }else{
            r = m - 1;
        }
    }
    vector<int> lft;
    for(int i = 1; i + ans - 1 <= n; i++){
        if(mn.query(i, i + ans - 1) == gc.query(i, i + ans - 1)){
            lft.emplace_back(i);
        }
    }
    cout << (int) lft.size() << ' ' << ans - 1 << '\n';
    for(auto x : lft){
        cout << x << ' ';
    }
    return 0;
}
