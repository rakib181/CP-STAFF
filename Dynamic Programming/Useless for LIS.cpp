#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9, inf = 1e9 + 7;
vector<int> a(N);
struct ST{
    int n;
    vector<int> t;
    ST(int n){
        this -> n = n;
        this -> t.assign(4 * n, 0);
    }
    void upd(int node, int b, int e, int i, int v){
        if(b > i or e < i)return;
        if(b == e){
            t[node] = v;
            return;
        }
        int m = (b + e) >> 1;
        upd(2 * node, b, m, i, v);
        upd(2 * node + 1, m + 1, e, i, v);
        t[node] = max(t[2 * node], t[2 * node + 1]);
    }

    int query(int node, int b, int e, int l, int r){
        if(b > r or e < l)return 0;
        if(b >= l and e <= r)return t[node];
        int m = (b + e) >> 1;
        return max(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        set<int> se;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            se.insert(a[i]);
        }
        int id = 0;
        map<int, int> mp;
        for(auto x : se){
            mp[x] = ++id;
        }
        for(int i = 1; i <= n; i++){
            a[i] = mp[a[i]];
        }
        vector<int> dp1(n + 1, 0), dp2(n + 1, 0);
        ST seg(id);
        for(int i = 1; i <= n; i++){
            dp1[i] = 1;
            dp1[i] = max(dp1[i], seg.query(1, 1, id, 0, a[i] - 1) + 1);
            seg.upd(1, 1, id, a[i], dp1[i]);
        }
        ST st(id);
        for(int i = n; i >= 1; i--){
            dp2[i] = 1;
            dp2[i] = max(dp2[i], st.query(1, 1, id, a[i] + 1, id) + 1);
            st.upd(1, 1, id, a[i], dp2[i]);
        }
        int lcs = *max_element(dp1.begin() + 1, dp1.begin() + n + 1);
        vector<int> ans;
        for(int i = 1; i <= n; i++){
            if(dp1[i] + dp2[i] - 1 == lcs){
                ans.emplace_back(i);
            }
        }
        cout << (int) ans.size() << '\n';
        for(auto x : ans){
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}
