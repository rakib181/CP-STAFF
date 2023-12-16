#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 9;
int a[N];
struct item{
    vector<int> a;
    vector<ll> sum;
}t[4 * N];

item merge(item &x, item &y){
    item ans;
    int n = (int)x.a.size(), m = (int) y.a.size();
    int i = 0, j = 0;
    while(i < n and j < m){
        if(x.a[i] >= y.a[j]){
            ans.a.emplace_back(x.a[i++]);
        }else ans.a.emplace_back(y.a[j++]);
    }
    while(i < n){
        ans.a.emplace_back(x.a[i++]);
    }
    while(j < m){
        ans.a.emplace_back(y.a[j++]);
    }
    for(i = 0; i < (int) ans.a.size(); i++){
        if(!i)ans.sum.emplace_back(ans.a[i]);
        else ans.sum.emplace_back(ans.sum.back() + ans.a[i]);
    }
    return ans;
}

void build(int node, int b, int e){
    if(b == e){
        t[node].a.emplace_back(a[b]);
        t[node].sum.emplace_back(a[b]);
        return;
    }
    int m = (b + e) >> 1;
    build(2 * node, b, m);
    build(2 * node + 1, m + 1, e);
    t[node] = merge(t[2 * node], t[2 * node + 1]);
}

ll query(int node, int b, int e, int l, int r, int val){
    if(b > r or e < l)return 0;
    if(b >= l and e <= r){
        int L = 0, R = t[node].a.size() - 1, idx = -1;
        while(L <= R){
            int M = (L + R) >> 1;
            if(t[node].a[M] > val){
                idx = M;
                L = M + 1;
            }else R = M - 1;
        }
        return (idx != -1) ? t[node].sum[idx] : 0;
    }
    int m = (b + e) >> 1;
    return query(2 * node, b, m, l, r, val) + query(2 * node + 1, m + 1, e, l, r, val);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--) {
        int n, q;
        cin >> n >> q;
        for(int i = 1; i <= 4 * n; i++){
            t[i].a.clear();
            t[i].sum.clear();
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        build(1, 1, n);
        while (q--) {
            int l, r;
            cin >> l >> r;
            l += 1, r += 1;
            cout << query(1, 1, n, 1, l, a[r]) << ' ';
        }
        cout << '\n';
    }
    return 0;
}
