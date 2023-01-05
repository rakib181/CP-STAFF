#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct segment{
    int sz{};
    vector<int> a;
    void init(int n){
        sz = 1;
        while (sz < n) sz *= 2;
        a.assign(2 * sz, 0);
    }
    void set(int i, int val, int x, int lx, int rx){
        if(rx - lx == 1){
            a[x] = val;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            set(i, val, 2 * x + 1, lx, m);
        }else{
            set(i, val, 2 * x + 2, m, rx);
        }
        a[x] = a[2 * x + 1] + a[2 * x + 2];
    }
    void set(int i, int val){
        set(i, val, 0, 0, sz);
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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    segment st;
    int n;
    cin >> n;
    st.init(n);
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        st.set(i, 1);
    }
    int q = n;
    while (q--){
        int x;
        cin >> x;
        int l = 1, r = n, pos = 0;
        while (l <= r){
            int mid = (l + r) >> 1;
            if(st.query(0, mid) >= x){
                pos = mid;
                r = mid - 1;
            }else l = mid + 1;
        }
        cout << a[pos - 1] << ' ';
        st.set(pos - 1, 0);
    }
    return 0;
}
