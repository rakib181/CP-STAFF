#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct segment{
    int sz;
    vector<int> seg;
    void init(int n){
        sz = 1;
        while (sz < n) sz *= 2;
        seg.assign(2 * sz, 0);
    }
    void build(vector<int> &a, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < (int) a.size()) seg[x] = a[lx];
            return;
        }
        int m = (lx + rx) >> 1;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        seg[x] = max(seg[2 * x + 1], seg[2 * x + 2]);
    }
    void build(vector<int> &a){
        build(a, 0, 0, sz);
    }
    void update(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            seg[x] = v;
            return;
        }
        int m = (lx + rx) >> 1;
        if(i < m){
            update(i, v, 2 * x + 1, lx, m);
        }else{
            update(i, v, 2 * x + 2, m, rx);
        }
        seg[x] = max(seg[2 * x + 1], seg[2 * x + 2]);
    }
    void update(int i, int v){
        update(i, v, 0, 0, sz);
    }
    int query(int l, int r, int x, int lx, int rx){
        if(lx >= r or l >= rx)return INT_MIN;
        if(lx >= l and rx <= r)return seg[x];
        int m = (lx + rx) >> 1;
        return max(query(l, r, 2 * x + 1, lx, m), query(l, r, 2 * x + 2, m, rx));
    }
    int query(int l, int r){
        return query(l, r, 0, 0, sz);
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    segment st;
    int n, q;
    cin >> n >> q;
    st.init(n);
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    st.build(a);
    while (q--){
        int x;
        cin >> x;
        int l = 0, r = n, idx = -1;
        while (l <= r){
            int mid = (l + r) >> 1;
            if(st.query(0, mid) >= x){
                idx = mid - 1;
                r = mid - 1;
            }else l = mid + 1;
        }
        if(idx == -1)cout << "0" << ' ';
        else{
            cout << idx + 1 << ' ';
            a[idx] -= x;
            st.update(idx, a[idx]);
        }
    }
    return 0;
}

