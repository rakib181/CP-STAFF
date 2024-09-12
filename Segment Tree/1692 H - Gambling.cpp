#include<bits/stdc++.h>
using namespace std;

#define long long long int
const int no_op = 1e9 + 7;

struct item{
    int sub_sum{}, pref{}, suf{}, sum{};
    item() = default;
    item(int _sub_sum, int _pref, int _suf, int _sum) : sub_sum(_sub_sum), pref(_pref), suf(_suf), sum(_sum) {};
};

item merge(item x, item y){
    if(x.sum == no_op)return y;
    if(y.sum == no_op)return x;
    item ans{};
    ans.sub_sum = max({ans.sub_sum, x.sub_sum, y.sub_sum});
    ans.sub_sum = max(ans.sub_sum, x.suf + y.pref);
    ans.pref = max(x.pref, x.sum + y.pref);
    ans.suf = max(y.suf, y.sum + x.suf);
    ans.sum = x.sum + y.sum;
    return ans;
}

const int N = 2e5 + 9;
vector<item> t(4 * N);

void upd(int node, int b, int e, int i, int v){
    if(b > i or e < i)return;
    if(b == e){
        t[node] = {v, v, v, v};
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * node, b, m, i, v);
    upd(2 * node + 1, m + 1, e, i, v);
    t[node] = merge(t[2 * node], t[2 * node + 1]);
}

item query(int node, int b, int e, int l, int r){
    if(b > r or e < l)return {no_op, no_op, no_op, no_op};
    if(b >= l and e <= r)return t[node];
    int m = (b + e) >> 1;
    return merge(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        map<int, vector<int>> a;
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            a[x].emplace_back(i);
            upd(1, 1, n, i, -1);
        }
        int ans = 0, mx = 0;
        for(auto &[x, vec] : a){
            vector<int> b = vec;
            for(auto i : b){
                upd(1, 1, n, i, 1);
            }
            if(query(1, 1, n, 1, n).sub_sum > mx){
                ans = x;
                mx = query(1, 1, n, 1, n).sub_sum;
            }
            for(auto i : b){
                upd(1, 1, n, i, -1);
            }
        }
        vector<int> b(n + 1, -1);
        for(auto i : a[ans]){
            b[i] = 1;
        }
        int l = 1, ans_l = 0, ans_r = 0, sum = 0; mx = 0;
        for(int i = 1; i <= n; i++){
            sum += b[i];
            if(sum > mx){
                mx = sum;
                ans_l = l;
                ans_r = i;
            }
            if(sum < 0){
                sum = 0;
                l = i + 1;
            }
        }
        cout << ans << ' ' << ans_l << ' ' << ans_r << '\n';
    }
    return 0;
}
