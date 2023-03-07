#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 3e5 + 9;

struct node{
    int zero, one, two;
    node operator+(const node &other) const{
        node ans{};
        ans.zero = zero + other.zero;
        ans.one = one + other.one;
        ans.two = two + other.two;
        return ans;
    }
};

struct segment{
#define lc (node << 1)
#define rc (node << 1 | 1)
    node seg[4 * N]{}; int lazy[4 * N]{};
    void push(int node, int b, int e){
        if(lazy[node] % 3 == 0){
            lazy[node] = 0;
            return;
        }
        int add = lazy[node] % 3;
        if(add == 1){
            int zero = seg[node].zero, one = seg[node].one;
            seg[node].zero = seg[node].two;
            seg[node].one = zero;
            seg[node].two = one;
        }else{
            int zero = seg[node].zero;
            seg[node].zero = seg[node].one;
            seg[node].one = seg[node].two;
            seg[node].two = zero;
        }
        if(b != e){
            lazy[lc] += lazy[node];
            lazy[rc] += lazy[node];
        }
        lazy[node] = 0;
    }
    void pull(int node){
        seg[node] = seg[lc] + seg[rc];
    }
    node combine(node a, node b){
        return a + b;
    }
    void build(int node, int b, int e){
        lazy[node] = 0;
        if(b == e){
            seg[node].zero = 1;
            seg[node].one = 0;
            seg[node].two = 0;
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
            lazy[node] += v;
            push(node, b, e);
            return;
        }
        int m = (b + e) >> 1;
        upd(lc, b, m, l, r, v);
        upd(rc, m + 1, e, l, r, v);
        pull(node);
    }

    node query(int node, int b, int e, int l, int r){
        push(node, b, e);
        if(l > e or r < b)return {0, 0, 0};
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
    int tt, cs = 1;
    cin >> tt;
    while (tt--) {
        cout << "Case " << cs++ << ":" << '\n';
        int n, q;
        cin >> n >> q;
        st.build(1, 1, n);
        while (q--){
            int type;
            cin >> type;
            if(type == 0){
               int l, r;
               cin >> l >> r;
               l++, r++;
               st.upd(1, 1, n, l, r, 1);
            }else{
                int l, r;
                cin >> l >> r;
                l++, r++;
                cout << st.query(1, 1, n, l, r).zero << '\n';
            }
        }
    }
    return 0;
}
