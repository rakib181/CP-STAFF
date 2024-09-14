#include<bits/stdc++.h>
using namespace std;

#define long long long
const int N = 2e5 + 9;
long t[4 * N], lazy[4 * N];

void push(int node, int b, int e) {
    if (lazy[node] == 0)return;
    t[node] += 1LL * (e - b + 1) * lazy[node];
    if (b != e) {
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
    }
    lazy[node] = 0;
}


void upd(int node, int b, int e, int l, int r, int v) {
    push(node, b, e);
    if (b > r or e < l)return;
    if (b >= l and e <= r) {
        lazy[node] = v;
        push(node, b, e);
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * node, b, m, l, r, v);
    upd(2 * node + 1, m + 1, e, l, r, v);
    t[node] = t[2 * node] + t[2 * node + 1];
}

long query(int node, int b, int e, int l, int r) {
    push(node, b, e);
    if (b > r or e < l)return 0;
    if (b >= l and e <= r) {
        return t[node];
    }
    int m = (b + e) >> 1;
    return query(2 * node, b, m, l, r) + query(2 * node + 1, m + 1, e, l, r);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> cnt;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cnt[a[i]]++;
        upd(1, 1, n, i, i, (int) cnt.size());
    }
    map<int, vector<int>> id;
    for(int i = 1; i <= n; i++){
        id[a[i]].emplace_back(i);
    }
    for(auto &[_, vec] : id){
        vec.emplace_back(n + 1);
        reverse(vec.begin(), vec.end());
    }
    long ans = 0;
    for(int i = 1; i <= n; i++){
        auto l = id[a[i]].back();
        id[a[i]].pop_back();
        auto r = id[a[i]].back();
        ans += query(1, 1, n, i, n);
        upd(1, 1, n, l, r - 1, -1);
    }
    cout << ans;
    return 0;
}
