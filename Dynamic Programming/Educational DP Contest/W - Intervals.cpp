#include<bits/stdc++.h>
using namespace std;
#define long long long int
const int N = 2e5 + 9;
const long inf = 1e18 + 9;
vector<long> t(4 * N), lazy(4 * N,0);

void push(int node, int b, int e){
    t[node] += lazy[node];
    if(b != e){
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
    }
    lazy[node] = 0;
}

long merge(long x, long y){
    return max(x, y);
}

void upd(int node, int b, int e, int l, int r, long v){
    push(node, b, e);
    if(b > r or e < l)return;
    if(b >= l and e <= r){
        lazy[node] += v;
        push(node, b, e);
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * node, b, m, l, r, v);
    upd(2 * node + 1, m + 1, e, l, r, v);
    t[node] = merge(t[2 * node], t[2 * node + 1]);
}

long query(int node, int b, int e, int l, int r){
    push(node, b, e);
    if(b > r or e < l)return 0;
    if(b >= l and e <= r)return t[node];
    int m = (b + e) >> 1;
    return merge(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a[n + 1];
    for(int i = 1; i <= m; i++){
        int l, r, v;
        cin >> l >> r >> v;
        a[r].emplace_back(l, v);
    }
    for(int r = 1; r <= n; r++){
        long ans = query(1, 1, n, 1, r);
        upd(1, 1, n, r, r, ans);
        for(auto [l, v] : a[r]){
            upd(1, 1, n, l, r, v);
        }
    }
    cout << max(0LL, query(1, 1, n, 1, n)) << '\n';
    return 0;
}
