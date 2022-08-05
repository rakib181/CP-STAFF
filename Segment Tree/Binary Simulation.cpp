#include<bits/stdc++.h>
using namespace std;

class segment{
public:
    int n;
    vector<int> seg;
    void init(int _n){
        this -> n = _n;
        this -> seg.clear();
        this -> seg.resize(4 * n, 0);
    }
    void update(int node, int s, int e, int l, int r){
        if(s == l && e == r){
            seg[node] = !(seg[node]);
            return;
        }
        int mid = (s + e) >> 1;
       if(r <= mid) update(2 * node, s, mid, l, r);
       else if(mid < l) update(2 * node + 1, mid + 1, e, l, r);
       else{
           update(2 * node, s, mid, l, mid);
           update(2 * node + 1, mid + 1, e, mid + 1, r);
       }
    }

    int query(int node, int s, int e, int idx){
        if(s == idx && e == idx)return seg[node];
        if(seg[node]){
            seg[2 * node] = !(seg[2 * node]);
            seg[2 * node + 1] = !(seg[2 * node + 1]);
            seg[node] = 0;
        }
        int mid = ( s + e) >> 1;
        if(mid >= idx){
            return query(2 * node, s, mid, idx);
        }else{
            return query(2 * node + 1, mid + 1, e, idx);
        }
    }
}st;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt,idx1 = 1;
    cin >> tt;
    while(tt--) {
        cout << "Case " << idx1++ << ":" << '\n';
        string ss;
        cin >> ss;
        int n = ss.size();
        st.init(n);
        for(int i = 0; i < n; i++){
            if(ss[i] == '1'){
                st.update(1, 1, n, i + 1, i + 1);
            }
        }
        int q;
        cin >> q;
        while (q--) {
            char ch;
            cin >> ch;
            if (ch == 'I') {
                int l, r;
                cin >> l >> r;
                st.update(1, 1, n, l, r);
            } else {
                int idx;
                cin >> idx;
                cout << st.query(1, 1, n, idx) << '\n';
            }
        }
    }
    return 0;
}
