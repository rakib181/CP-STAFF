#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 2e5 + 9;
int seg[4 * N];
void upd(int node, int b, int e, int idx, int v){
    if(b > idx or e < idx){
        return;
    }
    if(b == e and b == idx){
        seg[node] += v;
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * node, b, m, idx, v);
    upd(2 * node + 1, m + 1, e, idx, v);
    seg[node] = seg[2 * node] + seg[2 * node + 1];
}

int query(int node, int b, int e, int l, int r){
    if(b > r or e < l)return 0;
    if(b >= l and e <= r)return seg[node];
    int m = (b + e) >> 1;
    return query(2 * node, b, m, l, r) + query(2 * node + 1, m + 1, e, l, r);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        memset(seg, 0, sizeof seg);
       int n, cnt = 0;
       cin >> n;
       for(int i = 1; i <= n; i++){
          int v;
          cin >> v;
          cnt += query(1, 1, n, v, n);
          upd(1, 1, n, v, 1);
       }
       cout << cnt << '\n';
    }
    return 0;
}
