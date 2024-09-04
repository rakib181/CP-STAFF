#include<bits/stdc++.h>
using namespace std;

#define long long long int
const long inf = 1e18 + 9;

struct item{
    long mn, lazy;
    item(): mn(inf), lazy(inf) {};
};
const int N = 2e5 + 9;
vector<item> t(4 * N);
int n, k;
string s;

item merge(item x, item y){
    item ans{};
    ans.mn = min(x.mn, y.mn);
    return ans;
}

void push(int node, int b, int e){
    t[node].mn = min(t[node].mn, t[node].lazy);
    if(b != e){
        t[2 * node].lazy = min(t[2 * node].lazy, t[node].lazy);
        t[2 * node + 1].lazy = min(t[2 * node + 1].lazy, t[node].lazy);
    }
    t[node].lazy = inf;
}

void upd(int node, int b, int e, int l, int r, long v){
    push(node, b, e);
    if(b > r or e < l)return;
    if(b >= l and e <= r){
        t[node].lazy = min(t[node].lazy, v);
        push(node, b, e);
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * node, b, m, l, r, v);
    upd(2 * node + 1, m + 1, e, l, r, v);
    t[node] = merge(t[2 * node], t[2 * node + 1]);
}

item query(int node, int b, int e, int l, int r){
    push(node, b, e);
    if(b > r or e < l)return {};
    if(b >= l and e <= r){
        return t[node];
    }
    int m = (b + e) >> 1;
    return merge(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k >> s;
    s = '$' + s;
    upd(1, 0, n, 0, 0, 0);
    for(int i = 1; i <= n; i++){
        upd(1, 0, n, i, i, query(1, 0, n, i - 1, i - 1).mn + i);
        if(s[i] == '1'){
            upd(1, 0, n, max(0, i - k - 1), min(n, i + k), query(1, 0, n, max(0, i - k - 1), i).mn + i);
        }
    }
    cout << query(1, 0, n, n, n).mn << '\n';
    return 0;
}
