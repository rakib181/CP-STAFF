#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 1e5 + 9;
vector<int> A;

struct segment{
#define lc (node << 1)
#define rc (node << 1 | 1)
    int seg[4 * N]{}, lazy[4 * N]{};
    void init(){
        memset(seg, 0, sizeof seg);
        memset(lazy, 0, sizeof lazy);
    }
    void push(int node, int b, int e){
        if(lazy[node] == 0)return;
        seg[node] +=  lazy[node] * (e - b + 1);
        if(b != e){
            lazy[lc] += lazy[node];
            lazy[rc] += lazy[node];
        }
        lazy[node] = 0;
    }
    void pull(int node){
        seg[node] = seg[lc] + seg[rc];
    }
    static int combine(int a, int b){
        return a + b;
    }
    void build(int node, int b, int e){
        lazy[node] = 0;
        if(b == e){
            seg[node] = A[b];
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
}se;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    A.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }
    se.init();
    se.build(1, 1, n);
    int q;
    cin >> q;
    while (q--){
        int type;
        cin >> type;
        if(type == 1){
           int i, x, s;
           cin >> i >> x >> s;
           i++;
           se.upd(1, 1, n, 1, n, -s);
           se.upd(1, 1, n, i, i, s + x);
        }else{
            int i;
            cin >> i;
            i++;
            cout << se.query(1, 1, n, i, i) << '\n';
        }
    }
    return 0;
}
