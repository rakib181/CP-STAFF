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
        seg[node] =  lazy[node];
        if(b != e){
            lazy[lc] = lazy[node];
            lazy[rc] = lazy[node];
        }
        lazy[node] = -1;
    }
    void pull(int node){
        seg[node] = max(seg[lc] , seg[rc]);
    }
    int combine(int a, int b){
        return max(a, b);
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
            return (lazy[node] != -1) ? lazy[node] : seg[node];
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
            int i;
            cin >> i;
            i++;
            cout << st.query(1, 1, n, i, i) << '\n';
        }
    }
    return 0;
}
\\Another
#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct segment{
    int sz{}, NO_OPERATION = LONG_LONG_MAX;
    vector<int> a;
    void init(int n){
        sz = 1;
        while (sz < n) sz *= 2;
        a.assign(2 * sz, 0);
    }
    int operation(int a, int b) const{
        if(b == NO_OPERATION)return a;
        return b;
    }
    void apply_operation(int &a, int b) const{
        a = operation(a, b);
    }

    void propagate(int x, int lx, int rx){
        if(rx - lx == 1)return;
        apply_operation(a[2 * x + 1], a[x]);
        apply_operation(a[2 * x + 2], a[x]);
        a[x] = NO_OPERATION;
    }
    void add(int l, int r, int v, int x, int lx, int rx){
        propagate(x, lx, rx);
        if(lx >= r or l >= rx)return;
        if(lx >= l and rx <= r){
            apply_operation(a[x], v);
            return;
        }
        int m = (lx + rx) / 2;
        add(l, r, v, 2 * x + 1, lx, m);
        add(l, r, v, 2 * x + 2, m, rx);

    }
    void add(int l, int r, int v){
        add(l, r, v, 0, 0, sz);
    }
    int get(int i, int x, int lx, int rx){
        if(rx - lx == 1){
            return a[x];
        }
        int m = (lx + rx) / 2, res;
        if(i < m){
            res = get(i, 2 * x + 1, lx, m);
        }else{
            res = get(i, 2 * x + 2, m, rx);
        }
        return operation(res, a[x]);
    }
    int get(int i){
        return get(i, 0, 0, sz);
    }

};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    segment st;
    int n, m;
    cin >> n >> m;
    st.init(n);
    while (m--){
       int type;
       cin >> type;
       if(type == 1){
           int l, r, v;
           cin >> l >> r >> v;
           st.add(l, r, v);
       }else{
           int i;
           cin >> i;
           cout << st.get(i) << '\n';
       }
    }
    return 0;
}
