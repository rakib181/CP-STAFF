#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> ar(N);
class segment{
public:
    int n;
    vector<long long> seg;
    void init(int n){
        this -> n = n;
        seg.resize(4 * n, 0);
    }

    void build(int node, int s, int e){
        if(s == e){
            seg[node] = ar[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(2 * node, s, mid);
        build(2* node + 1, mid + 1, e);
        seg[node] = seg[2 * node] + seg[2 * node + 1];
    }
    void upd(int node, int s, int e, int idx, int val){
        if(s > idx || e < idx)return;
        if(s == idx && e == idx){
            seg[node] += val;
            return;
        }
        int mid = (s + e) >> 1;
        upd(2 * node, s, mid, idx, val);
        upd(2 * node + 1, mid + 1, e, idx, val);
        seg[node] = seg[2 * node] + seg[2 * node + 1];
    }
    long long query(int node, int s, int e, int l, int r){
        if(s > r || e < l)return 0;
        if(s >= l && e <= r){
            return seg[node];
        }
        int mid = (s + e) >> 1;
        return query(2 * node, s, mid, l, r) + query(2 * node + 1, mid + 1, e, l, r);
    }
} st;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt, idx = 1;
    cin >> tt;
    while(tt--){
        cout << "Case " << idx++ << ":" << '\n';
        int n, q;
        cin >> n >> q;
        st.init(n);
        for(int i = 1; i <= n; i++){
            cin >> ar[i];
        }
        st.build(1, 1, n);
        while(q--){
            int x;
            cin >> x;
            if(x == 1){
                int i;
                cin >> i;
              int val = ar[i + 1];
              cout << val << '\n';
              ar[i + 1] = 0;
              st.upd(1, 1, n, i + 1, -val);
            }else if(x == 2){
                int i, v;
                cin >> i >> v;
                ar[i + 1] += v;
                st.upd(1, 1, n, i + 1, v);
            }else{
                int l, r;
                cin >> l >> r;
               cout << st.query(1, 1, n, l + 1 , r + 1) << '\n';
            }
        }
    }
    return 0;
}
