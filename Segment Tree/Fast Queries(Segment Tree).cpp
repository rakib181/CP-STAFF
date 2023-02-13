#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 2e5 + 9;
vector<int> pre(N), loc(N);

struct node{
    int l, r, idx, ans;
};
bool cmp(node &a, node &b){
    if(a.l < b.l)return true;
    return false;
}
bool compare(node &a, node &b){
    if(a.idx < b.idx)return true;
    return false;
}

struct segment{
    int sz{};
    vector<int> a;
    void init(int n){
        sz = 1;
        while (sz < n) sz *= 2;
        a.assign(2 * sz, 0);
    }
    void build(vector<int> &v, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < (int) v.size())a[x] = v[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(v, 2 * x + 1, lx, m);
        build(v, 2 * x + 2, m, rx);
        a[x] = a[2 * x + 1] + a[2 * x + 2];
    }
    void build(vector<int> &v){
        build(v, 0, 0, sz);
    }
    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            a[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            set(i, v, 2 * x + 1, lx, m);
        }else{
            set(i, v, 2 * x + 2, m, rx);
        }
        a[x] = a[2 * x + 1] + a[2 * x + 2];
    }
    void set(int i, int v){
        set(i, v, 0, 0, sz);
    }
    int query(int l, int r, int x, int lx, int rx){
        if(lx >= r or l >= rx)return 0;
        if(lx >= l and rx <= r)return a[x];
        int m = (lx + rx) / 2;
        return query(l, r, 2 * x + 1, lx, m) + query(l, r, 2 * x + 2, m, rx);
    }
    int query(int l, int r){
        return query(l, r, 0, 0, sz);
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--){
        for(int i = 0; i < N; i++){
            loc[i] = 0, pre[i] = -1;
        }
        cout << "Case " << cs++ << ": " << '\n';
        segment st;
        int n, q;
        cin >> n >> q;
        st.init(n);
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            if(pre[x] == -1){
                a[i] = 1;
            }else loc[pre[x]] = i;
            pre[x] = i;
        }
        st.build(a);
        vector<node> query(q);
        for(int i = 0; i < q; i++){
            int l, r;
            cin >> l >> r;
            l--, r--;
            query[i].l = l, query[i].r = r, query[i].idx = i;
        }
        sort(query.begin(), query.end(), cmp);
        int j = 0;
        for(int i = 0; i < q; i++){
            while (j < query[i].l){
                if(loc[j] != 0){
                    st.set(loc[j], 1);
                }
                j++;
            }
            query[i].ans = st.query(query[i].l, query[i].r + 1);
        }
        sort(query.begin(), query.end(), compare);
        for(auto x : query){
            cout << x.ans << '\n';
        }
    }
    return 0;
}
