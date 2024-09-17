#include<bits/stdc++.h>
using namespace std;

#define long long long int

const int N = 2e5 + 9;
int lazy[4 * N]; long t[4 * N];

void push(int node, int b, int e) {
    if (lazy[node] == -1)return;
    t[node] = 1LL * (e - b + 1) * lazy[node];
    if (b != e) {
        lazy[2 * node] = lazy[node];
        lazy[2 * node + 1] = lazy[node];
    }
    lazy[node] = -1;
}

long merge(long x, long y) {
    return x + y;
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
    t[node] = merge(t[2 * node], t[2 * node + 1]);
}

long query(int node, int b, int e, int l, int r) {
    push(node, b, e);
    if (b > r or e < l)return 0;
    if (b >= l and e <= r) {
        return t[node];
    }
    int m = (b + e) >> 1;
    return merge(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1); vector<long> p(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }
    auto get = [&](int l, int r){
        return p[r] - p[l - 1];
    };
    vector<pair<int, int>> queries[n + 1];
    for(int i = 1; i <= q; i++){
        int l, r;
        cin >> l >> r;
        queries[l].emplace_back(r, i);
    }
    vector<long> ans(q + 1);
    vector<pair<int, int>> st;
    for(int i = n; i > 0; i--){
        while(!st.empty() and a[i] >= st.back().first){
            upd(1, 1, n, i, st.back().second, 0);
            st.pop_back();
        }
        upd(1, 1, n, i, st.empty() ? n : st.back().second - 1, a[i]);
        st.emplace_back(a[i], i);
        for(auto [j, id] : queries[i]){
            int l = 0, r = (int) st.size() - 1, valid = -1;
            while(l <= r){
                int m = (l + r) >> 1;
                if(st[m].second <= j){
                    valid = m;
                    r = m - 1;
                }else{
                    l = m + 1;
                }
            }
            ans[id] = query(1, 1, n, i, st[valid].second - 1) + 1LL * (j - st[valid].second + 1) * st[valid].first - get(st[valid].second, j) - get(i, st[valid].second - 1);
        }
    }
    for(int i = 1; i <= q; i++){
        cout << ans[i] << '\n';
    }
    return 0;
}
