#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 9;
vector<int> ar(N);
int n, q;

class segment{
public :
    int n;
    long long *seg, *lazy;
    void init(int n){
        this -> n = n;
        this -> seg = new long long [4 * n]{0};
        this -> lazy = new long long [4 * n]{0};
    }
    void push(int node, int s, int e){
        if(lazy[node] == 0)return;
        seg[node] += lazy[node] * (e - s + 1);
        if(s != e){
          lazy[2 * node + 1] += lazy[node];
          lazy[2 * node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }
    void build(int node, int s, int e){
        if(s == e){
            seg[node] = ar[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(2 * node + 1, s, mid);
        build(2 * node + 2, mid + 1, e);
        seg[node] += seg[2 * node + 1] + seg[2 * node + 2];
    }
    void update(int node, int s, int e, int i, int j, int val){
        push(node, s, e);
        if(s > j || e < i)return;
        if(s >= i && e <= j){
            lazy[node] += val;
            push(node, s, e);
            return;
        }
        int mid = (s + e) >> 1;
        update(2 * node + 1, s, mid, i, j, val);
        update(2 * node + 2, mid + 1, e, i , j, val);
        seg[node] += seg[2 * node + 1] + seg[2 * node + 2];
    }
    long long query(int node, int s, int e, int l, int r){
        if(s > r || e < l)return 0;
        if(s >= l && e <= r)return seg[node];
        int mid = (s + e) >> 1;
        return query(2 * node + 1, s, mid, l, r) + query(2 * node + 2, mid + 1, e, l , r);
    }
} st;

int32_t  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    st.init(n);
    for (int i = 1; i <= n; ++i) {
       cin >> ar[i];
    }
    st.build(1, 1, n);
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << st.query(1, 1, n, l, r) << '\n';
    }
    return 0;
}
