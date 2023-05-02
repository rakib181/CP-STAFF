#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int a[N], t[4 * N];

int merge(int x, int y){
    return __gcd(x, y);
}
void build(int node, int b, int e){
    if(b == e){
        t[node] = a[b];
        return;
    }
    int m = (b + e) >> 1;
    build(2 * node, b, m);
    build(2 * node + 1, m + 1, e);
    t[node] = merge(t[2 * node], t[2 * node + 1]);
}

int query(int node, int b, int e, int l, int r){
    if(b > r or e < l)return 0;
    if(b >= l and e <= r)return t[node];
    int m = (b + e) >> 1;
    return merge(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1, 1, n);
    int ans = 1;
    for(int i = 1; i <= n; i++){
        int x = 0, y = 0;
        int l1 = 1, r1 = i - 1, l2 = i + 1, r2 = n;
        if(l1 <= r1){
            x = query(1, 1, n, l1, r1);
        }
        if(l2 <= r2){
            y = query(1, 1, n, l2, r2);
        }
        ans = max(ans, __gcd(x, y));
    }
    cout << ans << '\n';
    return 0;
}
