#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 1e15 + 9;

struct ST{
    vector<vector<ll>> t;
    vector<ll> a;
    int lg = 15;
    ST() = default;
    explicit ST(int n, vector<ll> b){
        this -> t.assign(lg, vector<ll> (n + 10, 0));
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
    ll query(int l, int r){
        int _lg = __lg(r - l + 1) + 1;
        return max(t[_lg][l], t[_lg][r - (1 << (_lg - 1)) + 1]);
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<ll> dp(n + 1, -inf);
    for(int i = n - k + 1; i <= n; i++){
        dp[i] = a[i];
    }
    for(int it = 2; it <= m; it++){
        ST st(n, dp);
        st.build(n);
        for(int i = 1; i < n; i++){
            dp[i] = 1LL * a[i] + st.query(i + 1, min(n, i + k));
        }
        dp[n] = -inf;
    }
    ll ans = -inf;
    for(int i = 1; i <= k; i++){
        ans = max(ans, dp[i]);
    }
    if(ans < 0)ans = -1;
    cout << ans << '\n';
    return 0;
}
