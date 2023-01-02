#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct item{
    int cnt;
    int num[40];
};

struct segment{
    int sz{};
    item NEUTRAL_ELEMENT{};
    vector<item> a;
    void init(int n){
        NEUTRAL_ELEMENT.cnt = 0;
        for(int i = 0; i < 40; i++){
            NEUTRAL_ELEMENT.num[i] = 0;
        }
        sz = 1;
        while (sz < n) sz *= 2;
        a.assign(2 * sz, NEUTRAL_ELEMENT);
    }

    item merge(item x, item y){
        item ans = NEUTRAL_ELEMENT;
        ans.cnt = x.cnt + y.cnt;
        for(int i = 0; i < 40; i++){
            ans.num[i] = (x.num[i] or y.num[i]);
            if(x.num[i] == 1 and y.num[i] == 1){
                ans.cnt--;
            }
        }
        return ans;
    }
    void build(vector<int> &v, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < (int) v.size())a[x].num[v[lx]]++, a[x].cnt = 1;
            return;
        }
        int m = (lx + rx) / 2;
        build(v, 2 * x + 1, lx, m);
        build(v, 2 * x + 2, m, rx);
        a[x] = merge(a[2 * x + 1], a[2 * x + 2]);
    }
    void build(vector<int> &v){
        build(v, 0, 0, sz);
    }
    void set(int i, int prev, int val, int x, int lx, int rx){
        if(rx - lx == 1){
            a[x].num[prev] = 0;
            a[x].num[val] = 1;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            set(i, prev, val, 2 * x + 1, lx, m);
        }else{
            set(i, prev, val, 2 * x + 2, m, rx);
        }
        a[x] = merge(a[2 * x + 1], a[2 * x + 2]);
    }
    void set(int i, int prev, int val){
        set(i, prev, val, 0, 0, sz);
    }
    item query(int l, int r, int x, int lx, int rx){
        if(lx >= r or l >= rx)return NEUTRAL_ELEMENT;
        if(lx >= l and rx <= r)return a[x];
        int m = (lx + rx) / 2;
        return merge(query(l, r, 2 * x + 1, lx, m), query(l, r, 2 * x + 2, m, rx));
    }
    item query(int l, int r){
        return query(l, r, 0, 0, sz);
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    segment st;
    int n, m;
    cin >> n >> m;
    st.init(n);
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    st.build(a);
    while (m--){
        int type;
        cin >> type;
        if(type == 1){
            int l, r;
            cin >> l >> r;
            l--;
            cout << st.query(l, r).cnt << '\n';
        }else{
            int i, v;
            cin >> i >> v;
            i--, v--;
            st.set(i, a[i], v);
            a[i] = v;
        }
    }
    return 0;
}
