#include<bits/stdc++.h>
using namespace std;
#define long long long

const int N = 4e5 + 9;
const long inf = 1e16 + 9;
long t[4 * N];

long merge(long x, long y){
    return min(x, y);
}

void build(int node, int b, int e){
    if(b == e){
        t[node] = inf;
        return;
    }
    int m = (b + e) >> 1;
    build(2 * node, b, m);
    build(2 * node + 1, m + 1, e);
    t[node] = merge(t[2 * node], t[2 * node + 1]);
}

void upd(int node, int b, int e, int i, long v){
    if(b > i or e < i)return;
    if(b == e){
        t[node] = min(t[node], v);
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * node, b, m, i, v);
    upd(2 * node + 1, m + 1, e, i, v);
    t[node] = merge(t[2 * node], t[2 * node + 1]);
}

long query(int node, int b, int e, int l, int r){
    if(b > r or e < l)return inf;
    if(b >= l and e <= r){
        return t[node];
    }
    int m = (b + e) >> 1;
    return merge(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        int n;
        cin >> n;
        vector<int> a(n + 1), b(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> b[i];
        }
        build(1, 1, n);
        vector<int> g[n + 1];
        for(int i = 1; i <= n; i++){
           if(b[i] >= i) g[b[i]].emplace_back(i);
        }
        vector<long> dp(n + 1, inf);
        dp[1] = 0;
        upd(1, 1, n, 1, dp[1]);
        long ans = 0, sum = 0;
        for(int i = 2; i <= n; i++){
            for(auto j : g[i]){
                dp[i] = min(dp[i], query(1, 1, n, j, i - 1) + a[j]);
            }
            upd(1, 1, n, i, dp[i]);
        }
        for(int i = 1; i <= n; i++){
            sum += a[i];
            ans = max(ans, sum - dp[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}
