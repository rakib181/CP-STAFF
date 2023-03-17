#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 2e5 + 9;
int a[N], h[N], dp[N], t[4 * N];

void upd(int node, int b, int e, int idx, int v){
    if(b > idx or e < idx){
        return;
    }
    if(b == e and b == idx){
        t[node] = v;
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * node, b, m, idx, v);
    upd(2 * node + 1, m + 1, e, idx, v);
    t[node] = max(t[2 * node], t[2 * node + 1]);
}

int query(int node, int b, int e, int l, int r){
    if(b > r or e < l)return 0;
    if(b >= l and e <= r){
        return t[node];
    }
    int m = (b + e) >> 1;
    return max(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    dp[0] = a[0];
    upd(1, 1, N, h[0], dp[0]);
    for(int i = 1; i < n; i++){
        int mx = query(1, 1, N, 1, h[i] - 1);
        dp[i] = mx + a[i];
        upd(1, 1, N, h[i], dp[i]);
    }
    cout << *max_element(dp, dp + n) << '\n';
    return 0;
}
