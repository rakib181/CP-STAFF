#include<bits/stdc++.h>
using namespace std;

struct segment{
    int sz;
    vector<int> a;
    void init(int n){
        sz = 1;
        while (sz < n) sz *= 2;
        a.assign(2 * sz, 0);
    }
    void build(vector<int> &v, int x, int lx, int rx){
        if(rx - lx == 1){
           if(lx < (int) v.size()) a[x] = v[lx];
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
    int find(int k, int x, int lx, int rx){
        if(rx - lx == 1){
            return lx;
        }
        int m = (lx + rx) / 2;
        int sub = a[2 * x + 2];
        if(k < sub){
            return find(k, 2 * x + 2, m, rx);
        }else{
            return find(k - sub, 2 * x + 1, lx, m);
        }
    }
    int find(int k){
        return find(k, 0, 0, sz);
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    segment st;
    int n;
    cin >> n; st.init(n);
    vector<int> a(n, 1), ans(n);
    st.build(a);
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = n - 1; i >= 0; i--){
        ans[i] = st.find(a[i]);
        st.set(ans[i], 0);
        ans[i]++;
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
