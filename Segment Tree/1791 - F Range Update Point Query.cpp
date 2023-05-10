#include<bits/stdc++.h>
using namespace std;
#define  int long long int
const int N = 2e5 + 9;
int a[N] = {0};
int t[N * 4], lazy[N * 4];
bool done[N * 4];

void push(int node, int b, int e) {
    if (lazy[node] == 0) return;
    t[node] += lazy[node];
    int l = 2 * node, r = 2 * node + 1;
    if (b != e) {
        lazy[l] += lazy[node];
        lazy[r] += lazy[node];
    }
    lazy[node] = 0;
}

void build(int node, int b, int e) {
    lazy[node] = 0; done[node] = false;
    if (b == e) {
        t[node] = a[b];
        return;
    }
    int l = 2 * node, r = 2 * node + 1;
    int mid = (b + e) / 2;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[node] = 0;
}

int query(int node, int b, int e, int i) {
    push(node, b, e);
    if (i < b || i > e) return 0;
    if (b == e && b == i) {
        return t[node];
    }
    int l = 2 * node, r = 2 * node + 1;
    int mid = (b + e) / 2;
    if (i <= mid) return query(l, b, mid, i);
    else return query(r, mid + 1, e, i);
}

void upd(int node, int b, int e, int i, int j, int x) {
    push(node, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
        lazy[node] = x;
        push(node, b, e);
        return;
    }
    int l = 2 * node, r = 2 * node + 1;
    int mid = (b + e) / 2;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
}

int sumOfDigit(int n) {
    int sum = 0;
    while (n) {
        int r = n % 10;
        sum += r;
        n /= 10;
    }
    return sum;
}

void solve() {
    int n, m; cin >> n >> m;
    int ar[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    build(1, 1, n);
    while (m--) {
        int op, l, r, i;
        cin >> op;
        if (op == 1) {
            cin >> l >> r;
            upd(1, 1, n, l, r, 1);
        } else {
            cin >> i;
            if(!done[i]) {
                int x = query(1, 1, n, i);
                int cnt = 0, val = ar[i];
                if(x > 2) x = 3;
                while (x--) {
                    cnt++;
                    val = sumOfDigit(val);
                }
                if (val < 10)done[i] = true, ar[i] = val;
                cout << val << '\n';
            }else cout << ar[i] << '\n';
        }
    }

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

// Another cool approach
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int a[N], t[4 * N], lazy[4 * N];
bool done[4 * N];

void push(int node, int b,int e){
    if(lazy[node] == 0)return;
    t[node] += lazy[node];
    if(b != e){
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
    }
    lazy[node] = 0;
}

void build(int node, int b, int e){
    lazy[node] = 0; done[node] = false;
    if(b == e){
        t[node] = 0;
        return;
    }
    int m = (b + e) >> 1;
    build(2 * node, b, m);
    build(2 * node + 1, m + 1, e);
    t[node] = 0;
}

void upd(int node, int b, int e, int l, int r, int v){
    push(node, b, e);
    if(b > r or e < l)return;
    if(b >= l and e <= r){
        lazy[node] = v;
        push(node, b, e);
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * node, b, m, l, r, v);
    upd(2 * node + 1, m + 1, e, l, r, v);
}

int query(int node, int b, int e, int i){
    push(node, b, e);
    if(b > i or e < i)return 0;
    if(b == e)return t[node];
    int m = (b + e) >> 1;
    return query(2 * node, b, m, i) + query(2 * node + 1, m + 1, e, i);
}

int sod(int n){
    if(n <= 0)return 0;
    return (n % 10) + sod(n / 10);
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--) {
        int n, q;
        cin >> n >> q;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        build(1, 1, n);
        while (q--) {
            int type;
            cin >> type;
            if (type == 1) {
                int l, r;
                cin >> l >> r;
                upd(1, 1, n, l, r, 1);
            } else {
                int i;
                cin >> i;
                if (!done[i]) {
                    int x = query(1, 1, n, i);
                    if (x > 2) x = 3;
                    int val = a[i];
                    while (x--) {
                        val = sod(val);
                    }
                    if (val < 10) done[i] = true, a[i] = val;
                    cout << val << '\n';
                } else {
                    cout << a[i] << '\n';
                }
            }
        }
    }
    return 0;
}

