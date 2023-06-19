#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9, B = 11, MOD = 4001;
int Copy[N], a[N], lazy[4 * N];
struct node {
    int on[B], off[B];
};
node t[4 * N];

node merge(node x, node y) {
    node ans{};
    for (int i = 0; i < B; i++) {
        ans.on[i] = x.on[i] + y.on[i];
        ans.off[i] = x.off[i] + y.off[i];
    }
    return ans;
}

void push(int n, int b, int e) {
    if (lazy[n] == 0)return;
    for (int i = 0; i < B; i++) {
        if ((lazy[n] >> i) & 1) {
            swap(t[n].on[i], t[n].off[i]);
        }
    }
    if (b != e) {
        lazy[2 * n] ^= lazy[n];
        lazy[2 * n + 1] ^= lazy[n];
    }
    lazy[n] = 0;
}

void build(int n, int b, int e) {
    lazy[n] = 0;
    if (b == e) {
        for (int i = 0; i < B; i++) {
            if ((a[b] >> i) & 1) {
                t[n].on[i] = 1;
                t[n].off[i] = 0;
            } else {
                t[n].on[i] = 0;
                t[n].off[i] = 1;
            }
        }
        return;
    }
    int m = (b + e) >> 1;
    build(2 * n, b, m);
    build(2 * n + 1, m + 1, e);
    t[n] = merge(t[2 * n], t[2 * n + 1]);
}

void upd(int n, int b, int e, int l, int r, int v) {
    push(n, b, e);
    if (b > r or e < l)return;
    if (b >= l and e <= r) {
        lazy[n] = v;
        push(n, b, e);
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * n, b, m, l, r, v);
    upd(2 * n + 1, m + 1, e, l, r, v);
    t[n] = merge(t[2 * n], t[2 * n + 1]);
}

node query(int n, int b, int e, int l, int r) {
    push(n, b, e);
    if (b > r or e < l) {
        node ans{};
        memset(ans.on, 0, sizeof ans.on);
        memset(ans.off, 0, sizeof ans.off);
        return ans;
    }
    if (b >= l and e <= r) {
        return t[n];
    }
    int m = (b + e) >> 1;
    return merge(query(2 * n, b, m, l, r), query(2 * n + 1, m + 1, e, l, r));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        Copy[i] = a[i];
        a[i] ^= a[i - 1];
    }
    build(1, 0, n);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int p, v;
            cin >> p >> v;
            upd(1, 0, n, p, n, Copy[p]);
            Copy[p] = v;
            upd(1, 0, n, p, n, Copy[p]);
        } else {
            int l, r;
            cin >> l >> r;
            node ans = query(1, 0, n, l - 1, r);
            int f = 0;
            for (int i = 0; i < B; i++) {
                f += 1LL * ((1LL * ans.off[i] * ans.on[i]) * (1LL << i)) % MOD;
                f %= MOD;
            }
            cout << f << '\n';
        }
    }
    return 0;
}
