#include<bits/stdc++.h>
using namespace  std;
using ll = long long;

const int N = 2e5 + 9;

struct segment{
#define lc (node << 1)
#define rc (node << 1 | 1)
    ll seg[4 * N]{}, lazy[4 * N]{};
    segment(){
        memset(seg, 0, sizeof seg);
        memset(lazy, 0, sizeof lazy);
    }
    void push(int node, int b, int e){
        if(lazy[node] == 0)return;
        seg[node] = seg[node] + lazy[node] * (e - b + 1);
        if(b != e){
            lazy[lc] = lazy[lc] + lazy[node];
            lazy[rc] = lazy[rc] + lazy[node];
        }
        lazy[node] = 0;
    }
    void pull(int node){
        seg[node] = seg[lc] + seg[rc];
    }
    static ll combine(ll a, ll b){
        return a + b;
    }
    void build(int node, int b, int e){
        lazy[node] = 0;
        if(b == e){
            seg[node] = 0;
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

    ll query(int node, int b, int e, int l, int r){
        push(node, b, e);
        if(l > e or r < b)return 0;
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
            int l, r; ll a, d;
            cin >> l >> r >> a >> d;
            st.upd(1, 1, n, l, l, a);
            if(l + 1 <= r){
                st.upd(1, 1, n, l + 1, r, d);
            }
            if(r + 1 <= n){
                st.upd(1, 1, n, r + 1, r + 1,  -d * (r - l) - a);
            }
        }else{
            int idx;
            cin >> idx;
            cout << st.query(1, 1, n, 1, idx) << '\n';
        }
    }
    return 0;
}
