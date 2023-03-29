#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;

int lucky(int n){
    string s = to_string(n);
    int mx = 0, mn = 10;
    for(auto x : s){
        mx = max(mx, (x - '0'));
        mn = min(mn, (x - '0'));
    }
    return mx - mn;
}
int a[N];
void cal(){
    for(int i = 1; i < N; i++){
        a[i] = lucky(i);
    }
}
pair<int, int> seg[4 * N];
pair<int, int> Merge(int node){
    if(seg[2 * node].first > seg[2 * node + 1].first){
        return seg[2 * node];
    }else if(seg[2 * node].first < seg[2 * node + 1].first){
        return seg[2 * node + 1];
    }else return seg[2 * node];
}

void upd(int node, int b, int e, int idx, int v){
    if(b > idx or e < idx){
        return;
    }
    if(b == e and b == idx){
        seg[node] = {v, b};
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * node, b, m, idx, v);
    upd(2 * node + 1, m + 1, e, idx, v);
    seg[node] = Merge(node);
}

pair<int, int> MAX(pair<int, int> x, pair<int, int> y){
    if(x.first > y.first)return x;
    else if(x.first < y.first) return y;
    else return x;
}

pair<int, int> query(int node, int b, int e, int l, int r){
    if(b > r or e < l)return {INT_MIN, -1};
    if(b >= l and e <= r)return seg[node];
    int m = (b + e) >> 1;
    return MAX(query(2 * node, b, m, l, r) , query(2 * node + 1, m + 1, e, l, r));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    for(int i = 1; i < N; i++){
        upd(1, 1, N, i, a[i]);
    }
    int tt;
    cin >> tt;
    while(tt--){
        int l, r;
        cin >> l >> r;
        cout << query(1, 1, N, l, r).second << '\n';
    }
    return 0;
}
