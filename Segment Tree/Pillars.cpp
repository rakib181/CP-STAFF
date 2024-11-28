#include <bits/stdc++.h>
using namespace std;

#define long long long

const int N = 2e5 + 9;
vector<pair<int, int>> t(4 * N, {-1, -1});

void upd(int node, int b, int e, int i, pair<int, int> v){
    if(b > i or e < i)return;
    if(b == e){
        t[node] = max(t[node], v);
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * node, b, m, i, v);
    upd(2 * node + 1, m + 1, e, i, v);
    t[node] = max(t[2 * node], t[2 * node + 1]);
}

pair<int, int> query(int node, int b, int e, int l, int r){
    if(b > r or e < l)return {-1, -1};
    if(b >= l and e <= r)return t[node];
    int m = (b + e) >> 1;
    return max(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d;
    cin >> n >> d;
    vector<long> h(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    auto val = h;
    auto hh = h;
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    for(int i = 0; i < n; i++){
        hh[i] = lower_bound(val.begin(), val.end(), h[i]) - val.begin();
    }
    int sz = (int) val.size();
    vector<int> dp(n), p(n, -1);
    for(int i = 0; i < n; i++){
        dp[i] = 1;
        int l = int(lower_bound(val.begin(), val.end(), h[i] - d + 1) - val.begin() - 1);
        int r = int(lower_bound(val.begin(), val.end(), h[i] + d) - val.begin());
        {
            auto [dd, id] = query(1, 0, sz, 0, l);
            if(dd + 1 > dp[i]){
                dp[i] = dd + 1;
                p[i] = id;
            }
        }
        {
           auto [dd, id] = query(1, 0, sz, r, sz);
           if(dd + 1 > dp[i]){
               dp[i] = dd + 1;
               p[i] = id;
           }
        }
        upd(1, 0, sz, hh[i], {dp[i], i});
    }
    int tt = -1, ans = 0;
    for(int i = 0; i < n; i++){
        if(dp[i] > ans){
            ans = dp[i];
            tt = i;
        }
    }
    cout << ans << '\n';
    vector<int> path;
    while(tt != -1){
        path.emplace_back(tt);
        tt = p[tt];
    }
    reverse(path.begin(), path.end());
    for(auto x : path){
        cout << x + 1 << ' ';
    }
    return 0;
}
