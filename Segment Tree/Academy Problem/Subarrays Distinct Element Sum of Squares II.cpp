#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

struct ST{
    vector<int> sum, sqr, lazy;
    int n{};
    void INIT(int _n){
        this -> n = _n;
        this -> sum.assign(4 * n, 0);
        this -> sqr.assign(4 * n, 0);
        this -> lazy.assign(4 * n, 0);
    }

    void push(int node, int b, int e){
        if(!lazy[node])return;
         if(b != e){
             lazy[2 * node] = 1LL * (1LL * lazy[2 * node] + lazy[node]) % mod;
             lazy[2 * node + 1] = 1LL * (1LL * lazy[2 * node + 1] + lazy[node]) % mod;
         }
         int gap = (e - b + 1);
         int new_sum = 1LL * (1LL * sum[node] + (1LL * lazy[node] * gap) % mod) % mod;
         int new_sqr = 1LL * (1LL * sqr[node] + (2LL * lazy[node] * sum[node] % mod) + (1LL * lazy[node] * lazy[node] % mod * gap % mod)) % mod;
         sum[node] = new_sum;
         sqr[node] = new_sqr;
         lazy[node] = 0;
    }

    void upd(int node, int b, int e, int l, int r, int v){
        push(node, b, e);
        if(b > r or e < l)return;
        if(b >= l and e <= r){
            lazy[node] = v;
            push(node, b, e);
            return;
        }
        int m = (b + e) >> 1;
        upd(2 * node, b, m, l, r, v);
        upd(2 * node + 1, m + 1, e, l, r, v);
        sum[node] = 1LL * (1LL * sum[2 * node] + sum[2 * node + 1]) % mod;
        sqr[node] = 1LL * (1LL * sqr[2 * node] + sqr[2 * node + 1]) % mod;
    }
}tree;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    tree.INIT(n);
    int a[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    map<int, int> seen;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int l = 0;
        if(seen.count(a[i])){
            l = seen[a[i]];
        }
        l += 1;
        int r = i;
        tree.upd(1, 1, n, l, r, 1);
        ans = 1LL * (1LL * ans + tree.sqr[1]) % mod;
        seen[a[i]] = i;
    }
    cout << ans << '\n';
    return 0;
}
