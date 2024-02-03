/* Today's Target (Y, AL, AM)
Academic Dynamic Programming Problem Sets*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 9;
int n, d, a[N], t[4 * N], dp[N];

void upd(int node, int b, int e, int i, int v){
    if(b > i or e < i)return;
    if(b == e){
        t[node] = v;
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * node, b, m, i, v);
    upd(2 * node + 1, m + 1, e, i, v);
    t[node] = max(t[2 * node], t[2 * node + 1]);
}

int query(int node, int b, int e, int l, int r){
    if(b > r or e < l)return 0;
    if(b >= l and e <= r)return t[node];
    int m = (b + e) >> 1;
    return max(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> d;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ans = 1;
    for(int i = 1; i <= n; i++){
        int l = max(0, a[i] - d);
        int r = min(N - 1, a[i] + d);
        dp[i] = 1;
        int mx = query(1, 1, N, l, r);
        dp[i] = max(dp[i], mx + 1);
        ans = max(ans, dp[i]);
        upd(1, 1, N, a[i], dp[i]);
    }
    cout << ans << '\n';
    return 0;
}
