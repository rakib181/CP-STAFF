#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 3e5 + 9;

struct segment{
    #define lc (node << 1)
    #define rc (node << 1 | 1)
    int seg[4 * N]{}, lazy[4 * N]{};
    segment(){
        memset(seg, 0, sizeof seg);
        memset(lazy, -1, sizeof lazy);
    }
    void push(int node, int b, int e){
        if(lazy[node] == -1)return;
        seg[node] = lazy[node] * (e - b + 1);
        if(b != e){
            lazy[lc] = lazy[node];
            lazy[rc] = lazy[node];
        }
        lazy[node] = -1;
    }
    void pull(int node){
        seg[node] = seg[lc] + seg[rc];
    }
    int combine(int a, int b){
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
    void upd(int node, int b, int e, int l, int r, int v){
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

    int query(int node, int b, int e, int l, int r){
        push(node, b, e);
        if(l > e or r < b)return 0;
        if(b >= l and e <= r){
            return seg[node];
        }
        int m = (b + e) >> 1;
        return combine(query(lc, b, m, l, r), query(rc, m + 1, e, l, r));
    }
}st;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    st.build(1, 1, n);
    while (q--){
        int type;
        cin >> type;
        if(type == 1){
            int l, r, v;
            cin >> l >> r >> v;
            l++;
            st.upd(1, 1, n, l, r, v);
        }else{
            int l, r;
            cin >> l >> r;
            l++;
            cout << st.query(1, 1, n, l, r) << '\n';
        }
    }
    return 0;
}
