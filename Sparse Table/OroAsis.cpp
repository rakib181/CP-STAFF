#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
int n, a[N];

struct OR{
    const int inf = (int) 1e9 + 7;
    vector<vector<int>> sp;

    OR(){
        int lg = 32 - __builtin_clz(n);
        sp.assign(lg + 1, vector<int> (n + 1, 0));
        for(int i = 0; i < n; i++){
            sp[0][i] = a[i];
        }
        for(int i = 1; i <= lg; i++){
            for(int j = 0; j + (1 << (i - 1)) <= n; j++){
                sp[i][j] = sp[i - 1][j] | sp[i - 1][j + (1 << (i - 1))];
            }
        }
    }
    int query(int l, int r){
        if(l > r)return 0;
        int lg = __lg(r - l + 1);
        return sp[lg][l] | sp[lg][r - (1 << (lg)) + 1];
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        OR YO;
        const int inf = INT_MAX;
        int len = inf;
        for(int i = 0; i < n; i++){
            int l = i, r = n - 1, ans = -1;
            while(l <= r){
                int m = (l + r) >> 1;
                int val = YO.query(i, m);
                int baki = YO.query( 0, i - 1) | YO.query(m + 1, n - 1);
                if(val == baki){
                    ans = (m - i + 1);
                    r = m - 1;
                    continue;
                }
                if(val > baki){
                    r = m - 1;
                }else {
                    l = m + 1;
                }
            }
            if(ans != -1){
                len = min(len, ans);
            }
        }
        if(len == inf){
            cout << -1 << '\n';
        }else{
            cout << len << ' ';
            int ans = 0;
            for(int i = 0; i + len - 1 < n; i++){
                int val = YO.query(i, i + len - 1);
                int baki = YO.query(0, i - 1) | YO.query(i + len, n - 1);
                if(val == baki)ans += 1;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
