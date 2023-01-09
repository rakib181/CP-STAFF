#include<bits/stdc++.h>
using namespace std;
#define int long long int

static const int N = 1e6 + 9;
int a[N];

struct item{
    int val, sum;
    item(int x, int y){
        this -> val = x;
        this -> sum = y;
    }
};
vector<item> tree[4 * N];
void merge(vector<item> &node, vector<item> &lx, vector<item> &rx){
    int lx_sz = (int) lx.size(), rx_sz = (int) rx.size(), i = 0, j = 0;
    while (i < lx_sz and j < rx_sz){
        if(lx[i].val < rx[j].val){
            node.push_back(lx[i++]);
        }else{
            node.push_back(rx[j++]);
        }
    }
    while (i < lx_sz){
        node.push_back(lx[i++]);
    }
    while (j < rx_sz){
        node.push_back(rx[j++]);
    }
    for(int ii = 0; ii < (int) node.size(); ii++){
        if(ii) node[ii].sum = node[ii - 1].sum + node[ii].val;
        else node[ii].sum = node[ii].val;
    }
}
void build(int x, int lx, int rx){
    if(lx == rx){
        tree[x].emplace_back(a[rx], a[rx]);
        return;
    }
    int m = (lx + rx) / 2;
    build(2 * x, lx, m);
    build(2 * x + 1, m + 1, rx);
    merge(tree[x], tree[2 * x], tree[2 * x + 1]);
}

int search(vector<item> &v, int k){
    int l = 0, r = (int) v.size() - 1, ans = -1;
    while (l <= r){
        int m = (l + r) / 2;
        if(v[m].val < k){
            ans = m;
            l = m + 1;
        }else{
            r = m - 1;
        }
    }
    int res = 0;
    if(ans != -1){
        int val = v[ans].sum;
        int actual = (ans + 1) * k;
        res = actual - val;
    }
    return res;
}

int query(int x, int lx, int rx, int l, int r, int k){
    if(lx > r or rx < l)return 0;
    if(lx >= l and rx <= r){
        int cal = search(tree[x], k);
        return cal;
    }
    int m = (lx + rx) / 2;
    return query(2 * x, lx, m, l, r, k) + query(2 * x + 1, m + 1, rx, l, r, k);
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1, 1, n);
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << query(1, 1, n, l, r, k) << '\n';
    }
    return 0;
}
