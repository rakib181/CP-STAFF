#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> ar(N);

class segment{
public:
    int n;
    vector<int> seg;
    void init(int n){
        this -> n = n;
        this -> seg.resize(4 * n, 0);
    }
    void build(int node, int s, int e){
        if(s == e){
            seg[node] = ar[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(node << 1, s, mid);
        build((node << 1) + 1, mid + 1, e);
        seg[node] = min(seg[node << 1], seg[(node << 1) + 1]);
    }
    int query(int node, int s, int e, int l, int r){
        if(s > r || e < l)return INT_MAX;
        if(s >= l && e <= r){
            return seg[node];
        }
        int mid = (s + e) >> 1;
        return min(query(node << 1, s, mid, l, r), query((node << 1) + 1, mid + 1, e, l, r));
    }
} st;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, idx = 1;
    cin >> tt;
    while(tt--) {
        cout << "Case " << idx++ << ":" << '\n';
        int n, q;
        cin >> n >> q;
        st.init(n);
        for (int i = 1; i <= n; i++) {
            cin >> ar[i];
        }
        st.build(1, 1, n);
        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << st.query(1, 1, n, l, r) << '\n';
        }
    }
    return 0;
}
