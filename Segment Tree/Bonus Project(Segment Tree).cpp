#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 5e5 + 9;
int A[N];
vector<int> g[N], st(N), en(N); int timer, n, q;
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
}se;

void DFS(int cur, int par){
    st[cur] = ++timer;
    for(auto x : g[cur]){
        if(x != par){
            DFS(x, cur);
        }
    }
    en[cur] = timer;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        timer = 0; se.init();
        cin >> n >> q;
        for(int i = 0; i < N; i++){
            g[i].clear();
            A[i] = 0, st[i] = 0, en[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }
        se.build(1, 1, n);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        DFS(1, -1);
        for(int i = 1; i <= n; i++){
            se.upd(1, 1, n, st[i], st[i], A[i]);
        }
        while (q--) {
            int x, v;
            cin >> x >> v;
            se.upd(1, 1, n, st[x], st[x], 2 * v);
            if(st[x] != en[x]) se.upd(1, 1, n, st[x] + 1, en[x], v);
        }
        for (int i = 1; i <= n; i++) {
            cout << se.query(1, 1, n, st[i], st[i]) << ' ';
        }
        cout << '\n';
    }
    return 0;
}
