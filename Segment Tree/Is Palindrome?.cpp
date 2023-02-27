#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 1e5 + 9, MOD = 1e9;

struct segment{
#define lc (node << 1)
#define rc (node << 1 | 1)
    vector<int> seg, lazy;
    segment(){
        seg.resize(4 * N, 0);
        lazy.resize(4 * N, 0);
    }
    void push(int node, int b, int e){
        if(lazy[node] == 0)return;
        seg[node] = lazy[node] * (e - b + 1);
        if(b != e){
            lazy[lc] = lazy[node];
            lazy[rc] = lazy[node];
        }
        lazy[node] = 0;
    }
    int combine(int a, int b){
        return a + b;
    }
    void pull(int node){
        seg[node] = seg[lc] + seg[rc];
    }
    void upd(int node, int b, int e, int l, int r, int val){
        push(node, b, e);
        if(l > e or r < b)return;
        if(b >= l and e <= r){
            lazy[node] = val;
            push(node, b, e);
            return;
        }
        int m = (b + e) >> 1;
        upd(lc, b, m, l, r, val);
        upd(rc, m + 1, e, l, r, val);
        pull(node);
    }

    int query(int node, int b, int e, int l, int r){
        push(node, b, e);
        if(l > e or r < b) return 0;
        if(b >= l and e <= r){
            return seg[node];
        }
        int m = (b + e) >> 1;
        return combine(query(lc, b, m, l, r), query(rc, m + 1, e, l, r));
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<segment> v(26);
    for(int i = 0; i < 26; i++){
        v[i].upd(1, 1, n, 1, n, MOD);
    }
    for(int i = 0; i < n; i++){
        v[s[i] - 'a'].upd(1, 1, n, i, i, 1);
    }
    int q;
    cin >> q;
    while (q--){
        int type;
        cin >> type;
        if(type == 1){
            int l, r; char c;
            cin >> l >> r >> c;
            int ind = c - 'a';
            for(int i = 0; i < 26; i++){
                if(i != ind){
                    v[i].upd(1, 1, n, l, r, MOD);
                }else{
                    v[i].upd(1, 1, n, l, r, 1);
                }
            }
        }else{
            int l, r;
            cin >> l >> r;
            int odd = 0;
            for(int i = 0; i < 26; i++){
                int x = v[i].query(1, 1, n, l, r);
                x %= MOD;
                if(x & 1)odd += 1;
            }
            if(odd <= 1) cout << "Yes" << '\n';
            else cout << "No" << '\n';
        }
    }
    return 0;
}
