#include<bits/stdc++.h>
using namespace  std;
using ll = long long;

const int N = 2e5 + 9;
const ll inf = 1e18 + 9;

struct segment{
#define lc (node << 1)
#define rc (node << 1 | 1)
    pair<ll, ll> seg[4 * N]{}; ll lazy[4 * N]{};
    void push(int node, int b, int e){
        seg[node].first += lazy[node];
        seg[node].second += lazy[node];
        if(b != e){
            lazy[lc] = lazy[lc] + lazy[node];
            lazy[rc] = lazy[rc] + lazy[node];
        }
        lazy[node] = 0;
    }
    void pull(int node){
        seg[node] = {min(seg[lc].first, seg[rc].first), max(seg[lc].second, seg[rc].second)};
    }
     static pair<ll, ll> combine(pair<ll, ll> a, pair<ll, ll> b){
        return {min(a.first, b.first), max(a.second, b.second)};
    }
    void build(int node, int b, int e){
        lazy[node] = 0;
        if(b == e){
            seg[node] = {0, 0};
            return;
        }
        int m = (b + e) >> 1;
        build(lc, b, m);
        build(rc, m + 1, e);
        pull(node);
    }
    void upd(int node, int b, int e, int l, int r, ll v){
        push(node, b, e);
        if(l > e or r < b) return;
        if(b >= l and e <= r){
            lazy[node] = v;
            push(node, b, e);
            return;
        }
        int m = (b + e) >> 1;
        upd(lc, b, m, l, r, v);
        upd(rc, m + 1, e, l, r, v);
        pull(node);
    }

    pair<ll, ll> query(int node, int b, int e, int l, int r){
        push(node, b, e);
        if(l > e or r < b)return {inf, -inf};
        if(b >= l and e <= r){
            return seg[node];
        }
        int m = (b + e) >> 1;
        return combine(query(lc, b, m, l, r), query(rc, m + 1, e, l, r));
    }
}st;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    st.build(1, 1, n);
    while(m--){
        int type;
        cin >> type;
        if(type == 1){
             int l, r;
             cin >> l >> r;
             if(l == r)cout  << "1\n";
             else{
                 auto ans = st.query(1, 1, n, l + 1, r);
                 if(ans.first == 0 and ans.second == 0)cout << "1\n";
                 else cout << "0\n";
             }
        }else{
            int l, r; ll a, d;
            cin >> l >> r >> a >> d;
            st.upd(1, 1, n, l, l, a);
            if(l + 1 <= r){
                st.upd(1, 1, n, l + 1, r, d);
            }
            if(r + 1 <= n){
                st.upd(1, 1, n, r + 1, r + 1,  -d * (r - l) - a);
            }
        }
    }
    return 0;
}
