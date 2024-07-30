#include<bits/stdc++.h>
using namespace std;
#define long long long int

const int N = 2e5 + 9, inf = 1e9 + 7;
int n, lazy[4 * N];
pair<int, int> t[4 * N];

pair<int, int> merge(pair<int, int> x, pair<int, int> y){
    if(x.first == inf)return y;
    if(y.first == inf)return x;
    if(x.first == y.first){
        return {x.first, x.second + y.second};
    }
    if(x.first < y.first){
        return x;
    }else{
        return y;
    }
}

void push(int node, int b, int e){
    t[node] = {t[node].first + lazy[node], t[node].second};
    if(b != e){
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
    }
    lazy[node] = 0;
}

void build(int node, int b, int e){
    lazy[node] = 0;
    if(b == e){
        t[node] = {0, 1};
        return;
    }
    int m = (b + e) >> 1;
    build(2 * node, b, m);
    build(2 * node + 1, m + 1, e);
    t[node] = merge(t[2 * node], t[2 * node + 1]);
}

void upd(int node, int b, int e, int l, int r, int v){
    push(node, b, e);
    if(b > r or e < l)return;
    if(b >= l and e <= r){
        lazy[node] += v;
        push(node, b, e);
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * node, b, m, l, r, v);
    upd(2 * node + 1, m + 1, e, l, r, v);
    t[node] = merge(t[2 * node], t[2 * node + 1]);
}

pair<int, int> query(int node, int b, int e, int l, int r){
    push(node, b, e);
    if(b > r or e < l){
        return {inf, 0};
    }
    if(b >= l and e <= r){
        return t[node];
    }
    int m = (b + e) >> 1;
    return merge(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int m;
       cin >> n >> m;
       for(int i = 0; i <= 4 * n; i++){
           t[i] = {0, 0};
       }
       build(1, 1, n);
       vector<pair<int, int>> a(m);
       vector<int> s[n + 1], e[n + 1];
       for(int i = 0; i < m; i++){
           cin >> a[i].first >> a[i].second;
           s[a[i].first].emplace_back(i);
           e[a[i].second].emplace_back(i);
       }
       for(int i = 0; i < m; i++){
           upd(1, 1, n, a[i].first, a[i].second - 1, 1);
       }
       auto it =  query(1, 1, n, 1, n);
       int ans = it.second;
       for(int i = 1; i <= n; i++){
           for(auto j : s[i]){
               upd(1, 1, n, a[j].first, a[j].second - 1, -1);
               upd(1, 1, n, 1, a[j].first - 1, 1);
               upd(1, 1, n, a[j].second, n, 1);
           }
           for(int j : e[i]){
               upd(1, 1, n, 1, a[j].first - 1, -1);
               upd(1, 1, n, a[j].second, n, -1);
               upd(1, 1, n, a[j].first, a[j].second - 1, 1);
           }
           it = query(1, 1, n, 1, n);
           ans = max(ans, it.second);
       }
       cout << n - ans << '\n';
    }
    return 0;
}
