#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct segment{
    int sz{};
    vector<int> a;
    void init(int n){
        sz = 1;
        while (sz < n)sz *= 2;
        a.assign(2 * sz, INT_MIN);
    }
    void build(vector<int> &aa, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < (int) aa.size()){
                a[x] = aa[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(aa, 2 * x + 1, lx, m);
        build(aa, 2 * x + 2, m, rx);
        a[x] = max(a[2 * x + 1] , a[2 * x + 2]);
    }
    void build(vector<int> &aa){
        build(aa, 0, 0, sz);
    }
    int query(int l, int r, int x, int lx, int rx){
        if(lx >= r or l >= rx)return INT_MIN;
        if(lx >= l and rx <= r)return a[x];
        int m = (lx + rx) / 2;
        return max(query(l, r, 2 * x + 1, lx, m) , query(l, r, 2 * x + 2, m, rx));
    }
    int query(int l, int r){
        return query(l, r, 0, 0, sz);
    }
};


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    segment st;
    int n, k, p;
    cin >> n >> k >> p;
    k = min(k, n);
    vector<int> a(2 * n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i + n] = a[i];
    }
    vector<int> cnt;
    for(int i = 0; i < 2 * n; i++){
        a[i] += (i ? a[i - 1] : 0);
        if(i == k - 1) cnt.push_back(a[i]);
        else if(i >= k) cnt.push_back(a[i] - a[i - k]);
    }
    st.init((int) cnt.size());
    st.build(cnt); int ptr = n;
    while (p--){
        char c;
        cin >> c;
        if(c == '!'){
            ptr--;
            if(!ptr) ptr = n;
        }else{
            cout << st.query(ptr, ptr + n - k + 1) << '\n';
        }
    }
    return 0;
}
