#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct ST{
    vector<vector<int>> t;
    vector<int> a;
    int lg = 25;
    ST()= default;
    explicit ST(int n, const int *a){
        this -> t.assign(lg, vector<int> (n + 2, 0));
        this -> a.assign(n + 2, 0);
        for(int i = 1; i <= n; i++){
            this -> a[i] = a[i];
        }
    }
    void build(int n){
        for(int i = 1; i <= n; i++){
            t[1][i] = a[i];
        }
        for(int i = 1; i < lg; i++){
            for(int j = 1; j + (1 << (i - 1)) <= n; j++){
                 t[i + 1][j] = t[i][j] & t[i][j + (1 << (i - 1))];
            }
        }
    }
    int query(int l, int r){
        int _lg = __lg(r - l + 1) + 1;
        return t[_lg][l] & t[_lg][r - (1 << (_lg - 1)) + 1];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n + 1], p[n + 1];
        p[0] = 0; map<int, vector<int>> pos;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            p[i] = p[i - 1] ^ a[i];
            pos[p[i]].emplace_back(i);
        }
        ST st (n, a);
        st.build(n);
        ll ans = 0;
        for(int l = 1; l <= n; l++){
            for(int r = l; r <= n; r++){
                int cur = st.query(l, r), lo = r, hi = n, r2 = r;
                while(lo <= hi){
                    int m = (lo + hi) >> 1;
                    if(st.query(l, m) == cur){
                        r = m;
                        lo = m + 1;
                    }else{
                        hi = m - 1;
                    }
                }
                int need = p[l - 1] ^ cur;
                vector<int> &x = pos[need];
                auto it1 = upper_bound(x.begin(), x.end(), r);
                auto it2 = lower_bound(x.begin(), x.end(), r2);
                ans += (it1 - it2);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
