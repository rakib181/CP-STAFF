#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct MX{
    const int inf = (int) 1e9 + 7;
    vector<vector<int>> sp;

      MX(vector<int> &a, int n){
        int lg = 32 - __builtin_clz(n);
        sp.assign(lg + 1, vector<int> (n + 1, -inf));
        for(int i = 0; i < n; i++){
            sp[0][i] = a[i];
        }
        for(int i = 1; i <= lg; i++){
            for(int j = 0; j + (1 << (i - 1)) <= n; j++){
                sp[i][j] = max(sp[i - 1][j], sp[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int query(int l, int r){
        int lg = __lg(r - l + 1);
        return max(sp[lg][l], sp[lg][r - (1 << (lg)) + 1]);
    }
};

struct MN{
    const int inf = (int) 1e9 + 7;
    vector<vector<int>> sp;
    MN(vector<int> &a, int n){
        int lg = 32 - __builtin_clz(n);
        sp.assign(lg + 1, vector<int> (n + 1, inf));
        for(int i = 0; i < n; i++){
            sp[0][i] = a[i];
        }
        for(int i = 1; i <= lg; i++){
            for(int j = 0; j + (1 << (i - 1)) <= n; j++){
                sp[i][j] = min(sp[i - 1][j], sp[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int query(int l, int r){
        int lg = __lg(r - l + 1);
        return min(sp[lg][l], sp[lg][r - (1 << (lg)) + 1]);
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        ll a[n + 1];
        ll distance = 0;
        vector<pair<ll, int>> d;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            distance += a[i];
            d.emplace_back(abs(distance), i);
        }
        sort(d.begin(), d.end(), [](auto x, auto y) {
            if (x.first != y.first)return x.first < y.first;
            return x.second < y.second;
        });
        vector<int> p(n);
        for(int i = 0; i < n; i++){
            p[i] = d[i].second;
        }
        MX mx(p, n);
        MN mn(p, n);
        for(int i = 0; i < n; i++){
            p[i] = d[i].second;
        }
        int q;
        cin >> q;
        while (q--) {
            ll x;
            cin >> x;
            int L = -1;
            {
                int l = 0, r = n - 1, pos = -1;
                while(l <= r){
                    int m = (l + r) >> 1;
                    if(d[m].first >= x){
                        pos = m;
                        r = m - 1;
                    }else l = m + 1;
                }
                if(pos != -1){
                    L = pos;
                }
            }
            if(L == -1){
                cout << "-1\n";
            }else cout << mn.query(L, n - 1) << ' ' << mx.query(L, n - 1) << '\n';
        }
    }
    return 0;
}
