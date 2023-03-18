#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> dp;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if(it == dp.end())dp.push_back(x);
        else *it = x;
    }
    cout << (int) dp.size() << '\n';
    return 0;
}

// Cute Approach
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 2e5 + 9, inf = 1e16;
int seg[4 * N], DP[N];

void upd(int node, int b, int e, int idx, int v){
    if(b > idx or e < idx)return;
    if(b == e and b == idx){
        seg[node] = v;
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * node, b, m, idx, v);
    upd(2 * node + 1, m + 1, e, idx, v);
    seg[node] = max(seg[2 * node], seg[2 * node + 1]);
}

int query(int node, int b, int e, int l, int r){
    if(b > r or e < l) return -inf;
    if(b >= l and e <= r)return seg[node];
    int m = (b + e) >> 1;
    return max(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1); set<int> se;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        se.insert(a[i]);
    }
    map<int, int> mp; int id = 0;
    for(auto x : se){
        mp[x] = ++id;
    }
    for(int i = 1; i <= n; i++){
        a[i] = mp[a[i]];
    }
    for(int i = 1; i <= n; i++){
        DP[i] = 1;
        if(a[i] != 1) {
            int mx = query(1, 1, N, 1, a[i] - 1);
            DP[i] = max(DP[i], mx + 1);
        }
        upd(1, 1, N, a[i], DP[i]);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, DP[i]);
    }
    cout << ans << '\n';
    return 0;
}
