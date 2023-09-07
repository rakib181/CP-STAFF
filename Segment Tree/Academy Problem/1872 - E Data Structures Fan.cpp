#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int a[N];
string s;

struct node {
    int ones, zeros, xor_zeros, xor_ones;
};
node t[4 * N];
bool lazy[4 * N];

node merge(node x, node y) {
    node ans;
    ans.ones = ans.zeros = 0;
    ans.ones = (x.ones + y.ones);
    ans.zeros = (x.zeros + y.zeros);
    ans.xor_ones = x.xor_ones ^ y.xor_ones;
    ans.xor_zeros = x.xor_zeros ^ y.xor_zeros;
    return ans;
}

void push(int n, int b, int e) {
    if (!lazy[n])return;
    swap(t[n].ones, t[n].zeros);
    swap(t[n].xor_zeros, t[n].xor_ones);
    if (b != e) {
        lazy[2 * n] ^= true;
        lazy[2 * n + 1] ^= true;
    }
    lazy[n] = false;
}

void build(int n, int b, int e) {
    lazy[n] = false;
    if (b == e) {
        t[n].ones = t[n].zeros = 0;
        if (s[b] == '1') {
            t[n].ones = 1;
            t[n].xor_ones = a[b];
        } else{
            t[n].zeros = 1;
            t[n].xor_zeros = a[b];
        }
        return;
    }
    int m = (b + e) >> 1;
    build(2 * n, b, m);
    build(2 * n + 1, m + 1, e);
    t[n] = merge(t[2 * n], t[2 * n + 1]);
}

void upd(int n, int b, int e, int l, int r) {
    push(n, b, e);
    if (b > r or e < l)return;
    if (b >= l and e <= r) {
        lazy[n] = true;
        push(n, b, e);
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * n, b, m, l, r);
    upd(2 * n + 1, m + 1, e, l, r);
    t[n] = merge(t[2 * n], t[2 * n + 1]);
}

node query(int n, int b, int e, int l, int r) {
    push(n, b, e);
    if (b > r or e < l)return {0, 0};
    if (b >= l and e <= r)return t[n];
    int m = (b + e) >> 1;
    return merge(query(2 * n, b, m, l, r), query(2 * n + 1, m + 1, e, l, r));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        cin >> s;
        s = '$' + s;
        build(1, 1, n);
        int q;
        cin >> q;
        while(q--){
            int type;
            cin >> type;
            if(type == 1){
                int l, r;
                cin >> l >> r;
                upd(1, 1, n, l, r);
            }else{
               int g;
               cin >> g;
               auto ans = query(1, 1, n, 1, n);
               g ? cout << ans.xor_ones << ' ' : cout << ans.xor_zeros << ' ';
            }
        }
        cout << '\n';
        for(int i = 0; i <= 4 * n; i++){
            t[i] = {0, 0, 0, 0};
            lazy[i] = false;
        }
    }
    return 0;
}
