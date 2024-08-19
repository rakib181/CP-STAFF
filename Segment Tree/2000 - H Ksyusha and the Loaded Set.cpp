#include <bits/stdc++.h>
using namespace std;

#define long long long

const int N = 2e6 + 9;

struct ST{
    int n;
    vector<int> t;
    explicit ST(){
        this -> t.assign(4 * N, 0);
    }

    void upd(int node, int b, int e, int i, int val){
        if(b > i or e < i)return;
        if(b == e){
            t[node] = val;
            return;
        }
        int m = (b + e) >> 1;
        upd(2 * node, b, m, i, val);
        upd(2 * node + 1, m + 1, e, i, val);
        t[node] = max(t[2 * node], t[2 * node + 1]);
    }

    int query(int node, int b, int e, int l, int r){
        if(b > r or e < l)return 0;
        if(b >= l and e <= r)return t[node];
        int m = (b + e) >> 1;
        return max(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ST st;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<int> se;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            se.insert(a[i]);
        }
        a.emplace_back(2e7);
        a[0] = 0;
        se.insert(0);
        se.insert(2e7);
        for(int i = 0; i <= n; i++){
            int gap = a[i + 1] - a[i] - 1;
            int l = a[i];
            st.upd(1, 0, N, l, gap);
        }
        auto add = [&](int x){
             se.insert(x);
             auto it = se.lower_bound(x);
             auto l = *prev(it);
             auto r = *next(it);
             st.upd(1, 0, N, l, 0);
             st.upd(1, 0, N, l, x - l - 1);
             st.upd(1, 0, N, x, r - x - 1);
        };
        auto remove = [&](int x){
            auto it = se.lower_bound(x);
            auto l = *prev(it);
            auto r = *next(it);
            st.upd(1, 0, N, l, 0);
            st.upd(1, 0, N, x, 0);
            st.upd(1, 0, N, l, r - l - 1);
            se.erase(x);
        };
        int m;
        cin >> m;
        while(m--){
            char type;
            cin >> type;
            if(type == '+'){
                int x;
                cin >> x;
                add(x);
            }else if(type == '-'){
                int x;
                cin >> x;
                remove(x);
            }else{
                int k;
                cin >> k;
                int l = 0, r = N, ans = 0;
                while(l <= r){
                    int mid = (l + r) >> 1;
                    if(st.query(1, 0, N, 0, mid) >= k){
                        ans = mid;
                        r = mid - 1;
                    }else{
                        l = mid + 1;
                    }
                }
                cout << ans + 1 << ' ';
            }
        }
        cout << '\n';
        for(auto x : se){
            st.upd(1, 0, N, x, 0);
        }
    }
    return 0;
}
