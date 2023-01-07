#include<bits/stdc++.h>
using namespace std;
#define int long long int
struct item{
    int A11, A12, A21, A22;
};

struct segment{
    int sz{};
    vector<item> a;
    item NEUTRAL_ELEMENT = {1, 0, 0, 1};
    void init(int n){
        sz = 1;
        while (sz < n) sz *= 2;
        a.assign(2 * sz, NEUTRAL_ELEMENT);
    }
    item merge(item &x, item &y, int MOD){
        int x1 = (((x.A11 * y.A11) % MOD) + ((x.A12 * y.A21) % MOD)) % MOD;
        int x2 = (((x.A11 * y.A12) % MOD) + ((x.A12 * y.A22) % MOD)) % MOD;
        int x3 = (((x.A21 * y.A11) % MOD) + ((x.A22 * y.A21) % MOD)) % MOD;
        int x4 = (((x.A21 * y.A12) % MOD) + ((x.A22 * y.A22) % MOD)) % MOD;
        return {x1, x2, x3, x4};
    }
    void build(vector<item> &v, int MOD, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < (int) v.size()) a[x] = v[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(v, MOD,2 * x + 1, lx, m);
        build(v, MOD,2 * x + 2, m, rx);
        a[x] = merge(a[2 * x + 1], a[2 * x + 2], MOD);
    }
    void build(vector<item> &v, int MOD){
        build(v, MOD, 0, 0, sz);
    }
    item query(int l, int r, int MOD, int x, int lx, int rx){
        if(lx >= r or l >= rx)return NEUTRAL_ELEMENT;
        if(lx >= l and rx <= r)return a[x];
        int m = (lx + rx) / 2;
        item item1 = query(l, r, MOD, 2 * x + 1, lx, m);
        item item2 = query(l, r, MOD, 2 * x + 2, m, rx);
        return merge(item1, item2, MOD);
    }
    item query(int l, int r, int MOD){
        return query(l, r, MOD, 0, 0, sz);
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    segment st;
    int MOD, n, q;
    cin >> MOD >> n >> q;
    st.init(n);
    vector<item> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].A11 >> a[i].A12 >> a[i].A21 >> a[i].A22;
        a[i].A11 = (a[i].A11 + MOD) % MOD;
        a[i].A12 = (a[i].A12 + MOD) % MOD;
        a[i].A21 = (a[i].A21 + MOD) % MOD;
        a[i].A22 = (a[i].A22 + MOD) % MOD;
    }
    st.build(a, MOD);
    while (q--){
        int l, r;
        cin >> l >> r;
        l--;
        item ans = st.query(l, r, MOD);
        cout << ans.A11 << ' ' << ans.A12 << '\n' << ans.A21 << ' ' << ans.A22 << '\n';
        cout << "\n\n";
    }
    return 0;
}
