#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// @author  heisenberg

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

#define long long long
typedef tree<pair<long, long>, null_type, greater<>, rb_tree_tag, tree_order_statistics_node_update> o_set;
const int inf = 1e9 + 7;
const int mod = 1e9 + 7;


struct segment_tree{
    vector<int> t, val;
    int n{};
    explicit segment_tree(int _n){
        this -> n = _n;
        this -> t.assign(4 * n, 0);
        this -> val.assign(n + 1, -1);
    }
    static int merge(int x, int y){
        return x + y;
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
        t[node] = merge(t[2 * node], t[2 * node + 1]);
    }
    int query(int node, int b, int e, int l, int r){
        if(b > r or e < l)return 0;
        if(b >= l and e <= r){
            return t[node];
        }
        int m = (b + e) >> 1;
        return merge(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
    }
};



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> ind(m);
    for(int i = 0; i < m; i++)cin >> ind[i];
    segment_tree st(n + 1);
    int index = 1;
    auto kth = [&](int k){
        int l = 1, r = n, ans = n + 5;
        while (l <= r){
            int m = (l + r) >> 1;
            if(st.query(1, 1, n, 1, m) >= k){
                ans = m;
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        return ans;
    };
    for(int i = 0; i < n; i++){
        int v;
        cin >> v;
        if(v != -1){
            st.upd(1, 1, n, index, 1);
            st.val[index++] = v;
        }else{
            vector<int> del;
            for(auto j : ind){
                int Kth = kth(j);
                if(Kth <= n){
                    del.emplace_back(Kth);
                }else{
                    break;
                }
            }
            for(auto j : del){
                st.upd(1, 1, n, j, 0);
            }
        }
    }
    bool f = false;
    for(int i = 1; i <= n; i++){
        if(st.query(1, 1, n, i, i) == 1){
            cout << st.val[i];
            f = true;
        }
    }
    if(!f){
        cout << "Poor stack!\n";
    }
    return 0;
}
