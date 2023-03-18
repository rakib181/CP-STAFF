#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 5005;
int A[N];
pair<int, int> seg[4 * N];

void merge(int node){
    if(seg[2 * node].first < seg[2 * node + 1].first){
        seg[node] = {seg[2 * node].first, seg[2 * node].second};
    }else if(seg[2 * node] > seg[2 * node + 1]){
        seg[node] = {seg[2 * node + 1].first, seg[2 * node + 1].second};
    }else{
        seg[node] = seg[2 * node];
    }
}

pair<int, int> MIN(pair<int, int> x, pair<int, int> y){
    if(x.first < y.first)return x;
    else return y;
}

void build(int node, int b, int e){
    if(b == e){
        seg[node] = {A[b], b};
        return;
    }
    int m = (b + e) >> 1;
    build(2 * node, b, m);
    build(2 * node + 1, m + 1, e);
    merge(node);
}

pair<int, int> query(int node, int b, int e, int l, int r){
    if(b > r or e < l) return {INT_MAX, INT_MAX};
    if(b >= l and e <= r)return seg[node];
    int m = (b + e) >> 1;
    return MIN(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
}
int n;
int cal(int l, int r, int h){
    if(l > r) return 0;
    pair<int, int> m = query(1, 1,  n, l, r);
    int mn = A[m.second];
    return min(r - l + 1, cal(l, m.second - 1, mn) + cal(m.second + 1, r, mn) + mn - h);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }
    A[0] = A[n + 1] = INT_MAX;
    build(1, 1, n);
    cout << cal(1, n, 0) << '\n';
    return 0;
}
