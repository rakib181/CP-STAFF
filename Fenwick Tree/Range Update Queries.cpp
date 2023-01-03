#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct BIT{
    int sz{};
    vector<int> seg;
    void init(int n){
        this -> sz = n;
        seg.assign(2 * sz, 0);
    }
    void update(int idx, int val){
        for(int i = idx; i <= sz; i += (-i & i)) seg[i] += val;
    }
    int query(int idx){
        int s = 0;
        for(int i = idx; i > 0; i -= (-i & i)){
            s += seg[i];
        }
        return s;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    BIT bt;
    int n, m;
    cin >> n >> m;
    bt.init(n);
    for(int i = 1; i <= n; i++){
        int val;
        cin >> val;
        bt.update(i, val);
        bt.update(i + 1, -val);
    }
    while (m--){
        int type;
        cin >> type;
        if(type == 1){
            int l, r, v;
            cin >> l >> r >> v;
            bt.update(l, v);
            bt.update(r + 1, -v);
        }else{
            int i;
            cin >> i;
            cout << bt.query(i) << '\n';
        }
    }
    return 0;
}
