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
        memset(lazy, 0, sizeof lazy);
    }
    void push(int node, int b, int e){
        if(lazy[node] == 0)return;
        seg[node] |= lazy[node];
        if(b != e){
            lazy[lc] |= lazy[node];
            lazy[rc] |= lazy[node];
        }
        lazy[node] = 0;
    }
    void pull(int node){
        seg[node] = seg[lc] & seg[rc];
    }
    int combine(int a, int b){
        return a & b;
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
        if(l > e or r < b)return -1;
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
    vector<pair<pair<int, int>, int>> Q;
    for(int i = 0; i < q; i++){
        int l, r, v;
        cin >> l >> r >> v;
        st.upd(1, 1, n, l, r, v);
        Q.push_back({{l, r}, v});
    }
    bool ok = true;
    for(auto x : Q){
        int l = x.first.first, r = x.first.second, v = x.second;
        if(st.query(1, 1, n, l, r) != v){
            ok = false;
            break;
        }
    }
    if(ok){
        cout << "YES" << '\n';
        for(int i = 1; i <= n; i++){
            cout << st.query(1, 1, n, i, i) << ' ';
        }
        cout << '\n';
    }else{
        cout << "NO" << '\n';
    }
    return 0;
}
