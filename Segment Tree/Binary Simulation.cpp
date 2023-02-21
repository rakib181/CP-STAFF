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


#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct segment{
    int sz{};
    vector<int> seg, operation;
    void init(int n){
        sz = 1;
        while (sz < n) sz *= 2;
        seg.assign(2 * sz, 0);
        operation.assign(2 * sz, 0);
    }
    void propagate(int x, int lx, int rx){
        seg[x] += operation[x];
        if(rx - lx != 1){
            operation[2 * x + 1] += operation[x];
            operation[2 * x + 2] += operation[x];
        }
        operation[x] = 0;
    }
    void add(int l, int r, int v, int x, int lx, int rx){
        propagate(x, lx, rx);
        if(lx >= r or l >= rx)return;
        if(lx >= l and rx <= r){
            operation[x] = v;
            propagate(x, lx, rx);
            return;
        }
        int m = (lx + rx) / 2;
        add(l, r, v, 2 * x + 1, lx, m);
        add(l, r, v, 2 * x + 2, m, rx);
        seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
    }
    void add(int l, int r, int v){
        add(l, r, v, 0, 0, sz);
    }
    int query(int i, int x, int lx, int rx){
        propagate(x, lx, rx);
        if(rx - lx == 1){
            return seg[x];
        }
        int m = (lx + rx) / 2;
        if(i < m){
            return query(i, 2 * x + 1, lx, m);
        }else{
            return query(i, 2 * x + 2, m, rx);
        }
    }
    int query(int i){
        return query(i, 0, 0, sz);
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--){
        cout << "Case " << cs++ << ":" << '\n';
        string s;
        cin >> s;
        int n = (int) s.size();
        segment st;
        st.init(n);
        int q;
        cin >> q;
        while (q--){
            char c;
            cin >> c;
            if(c == 'I'){
                int l, r;
                cin >> l >> r;
                l--;
                st.add(l, r, 1);
            }else{
                int i;
                cin >> i;
                i--;
               int x = st.query(i);
               if(x & 1){
                   if(s[i] == '1') {
                       cout << "0" << '\n';
                   }else{
                       cout << "1" << '\n';
                   }
               }else{
                   cout << (s[i] - '0') << '\n';
               }
            }
        }
    }
    return 0;
}
