#include<bits/stdc++.h>
using namespace std;

struct segment{
    int sz{};
    vector<int> a;
    void init(int n){
        sz = 1;
        while (sz < n) sz *= 2;
        a.assign(2 * sz, 0);
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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    segment st;
    int n;
    cin >> n; st.init(2 * n);
    vector<int> a(2 * n), pos(n, -1), ans(n);
    for(int i = 0; i < 2 * n; i++){
        cin >> a[i];
        a[i]--;
        if(pos[a[i]] == -1){
            pos[a[i]] = i;
        }else{
            ans[a[i]] = st.query(pos[a[i]], i);
            st.set(pos[a[i]], 1);
        }
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
