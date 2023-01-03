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
    int tt, cs = 1;
    cin >> tt;
    while (tt--) {
        cout << "Case " << cs++ << ":" << '\n';
        segment st;
        int n, m;
        cin >> n >> m;
        st.init(n + m + 1);
        vector<int> a(2e5 + 9, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            st.set(i, 1);
        }
        for (int i = 0; i < m; i++) {
            char c;
            cin >> c;
            if (c == 'a') {
                int x;
                cin >> x;
                a[n] = x;
                st.set(n, 1);
                n++;
            } else {
                int x;
                cin >> x;
                int l = 1, r = n, ans = 0;
                for(int step = 1; step <= 20; step++){
                    int mid = (l + r) / 2;
                    int pos = st.query(0, mid);
                    if(pos >= x){
                        ans = mid;
                        r = mid - 1;
                    }else l = mid + 1;
                }
                if(ans) {
                    cout << a[ans - 1] << '\n';
                    st.set(ans - 1, 0);
                }else cout << "none" << '\n';
            }
        }
    }
    return 0;
}
