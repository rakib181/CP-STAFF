#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 9;
const ll inf = 1e18 + 9;
vector<pair<ll, ll>> tree(4 * N, {0, inf});

ll fun(pair<ll, ll> line, ll x){
    return line.first * x + line.second;
}

void insert(int node, int b, int e, pair<ll, ll> line){
    int m = (b + e) >> 1;
    int lft = fun(line, b) < fun(tree[node], b);
    int mid = fun(line, m) < fun(tree[node], m);
    if(mid){
        swap(tree[node], line);
    }
    if(b == e)return;
    else if(lft != mid){
        insert(2 * node, b, m, line);
    }else{
        insert(2 * node + 1, m + 1, e, line);
    }
}

ll query(int node, int b, int e, ll x){
    int m = (b + e) >> 1;
    ll cur = fun(tree[node], x);
    if(b == e)return cur;
    if(x < m){
        return min(cur, query(2 * node, b, m, x));
    }else{
        return min(cur, query(2 * node + 1, m + 1, e, x));
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; ll c;
    cin >> n >> c;
    vector<int> h(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }
    vector<ll> dp(n + 1, 0);
    for(int i = 1; i <= n; i++){
        if(i != 1) dp[i] = c + 1LL * h[i] * h[i] + query(1, 1, N - 1, h[i]);
        insert(1, 1, N - 1, {-2LL * h[i], 1LL * h[i] * h[i] + dp[i]});
    }
    cout << dp[n] << '\n';
    return 0;
}
