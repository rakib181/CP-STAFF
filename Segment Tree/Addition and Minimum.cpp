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
        seg[node] +=  lazy[node];
        if(b != e){
            lazy[lc] += lazy[node];
            lazy[rc] += lazy[node];
        }
        lazy[node] = 0;
    }
    void pull(int node){
        seg[node] = min(seg[lc] , seg[rc]);
    }
    int combine(int a, int b){
        return min(a, b);
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
        if(l > e or r < b)return INT_MAX;
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
\\Another
#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct segment{
    int sz{};
    vector<int> operation, lazy;
    void init(int n){
        sz = 1;
        while (sz < n) sz *= 2;
        operation.assign(2 * sz, 0);
        lazy.assign(2 * sz, 0);
    }
    void add(int l, int r, int v, int x, int lx, int rx){
        if(lx >= r or l >= rx)return;
        if(lx >= l and rx <= r){
            operation[x] += v;
            lazy[x] += v;
            return;
        }
        int m = (lx + rx) / 2;
        add(l, r, v, 2 * x + 1, lx, m);
        add(l, r, v, 2 * x + 2, m, rx);
        lazy[x] = min(lazy[2 * x + 1], lazy[2 * x + 2]) + operation[x];
    }
    void add(int l, int r, int v){
        add(l, r, v, 0, 0, sz);
    }
    int get(int l, int r, int x, int lx, int rx){
        if(lx >= r or l >= rx)return INT_MAX;
        if(lx >= l and rx <= r){
            return lazy[x];
        }
        int m = (lx + rx) / 2;
        int m1 = get(l, r, 2 * x + 1, lx, m);
        int m2 = get(l, r, 2 * x + 2, m, rx);
        return min(m1, m2) + operation[x];
    }
    int get(int l, int r){
        return get(l, r, 0, 0, sz);
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
            int l, r;
            cin >> l >> r;
            cout << st.get(l, r) << '\n';
        }
    }
    return 0;
}
