#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e5 + 9;

struct ST{
    int t[4 * N];
    void upd(int node, int b, int e, int i, int v){
        if(b > i or e < i)return;
        if(b == e){
            t[node] = v;
            return;
        }
        int m = (b + e) >> 1;
        upd(2 * node, b, m, i, v);
        upd(2 * node + 1, m + 1, e, i, v);
        t[node] = t[2 * node] + t[2 * node + 1];
    }
    int query(int node, int b, int e, int l, int r){
        if(b > r or e < l)return 0;
        if(b >= l and e <= r)return t[node];
        int m = (b + e) >> 1;
        return query(2 * node, b, m, l, r) + query(2 * node + 1, m + 1, e, l, r);
    }
    void clear(int n){
        for(int i = 1; i <= 4 * n; i++){
            t[i] = 0;
        }
    }
}st, bob;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans[n + 1];
        memset(ans, 0, sizeof ans);
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            if(st.query(1, 1, n, 1, x - 1) == 0 or bob.query(1, 1, n, 1, x - 1) < st.query(1, 1, n, 1, x - 1)){
                ans[i] = 1;
                bob.upd(1, 1, n, x, 1);
            }
            st.upd(1, 1, n, x, 1);
        }
        cout << count(ans + 1, ans + n + 1, 0) << '\n';
        st.clear(n); bob.clear(n);
    }
    return 0;
}
