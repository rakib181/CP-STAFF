#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
vector<int> a(N);
struct item{
    vector<int> a;
    vector<ll> pref;
};

struct MST{
    vector<item> t;
    int n;
    explicit MST(int n){
        this -> n = n;
        this -> t.assign(3 * n, {{}, {}});
    }

    item merge(item x, item y){
        item ans;
        int i = 0, j = 0;
        int sz_x = (int) x.a.size(), sz_y = (int) y.a.size();
        while(i < sz_x and j < sz_y){
            if(x.a[i] > y.a[j]){
                ans.a.emplace_back(y.a[j++]);
            }else{
                ans.a.emplace_back(x.a[i++]);
            }
        }
        while(i < sz_x){
            ans.a.emplace_back(x.a[i++]);
        }
        while(j < sz_y){
            ans.a.emplace_back(y.a[j++]);
        }
        for(i = 0; i < (int) ans.a.size(); i++){
            if(!i)ans.pref.emplace_back(ans.a[i]);
            else{
                ans.pref.emplace_back(ans.pref.back() + ans.a[i]);
            }
        }
        return ans;
    }

    void build(int node, int b, int e){
        if(b == e){
            t[node].a.emplace_back(a[b]);
            t[node].pref.emplace_back(a[b]);
            return;
        }
        int m = (b + e) >> 1;
        build(2 * node, b, m);
        build(2 * node + 1, m + 1, e);
        t[node] = merge(t[2 * node], t[2 * node + 1]);
    }

    item query(int node, int b, int e, int l, int r){
        if(b > r or e < l)return {{}, {}};
        if(b >= l and e <= r){
            return t[node];
        }
        int m = (b + e) >> 1;
        return merge(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        MST ms(n);
        ms.build(1, 1, n);
        while(q--) {
            int k;
            cin >> k;
            auto it = ms.query(1, 1, n, 1, k);
            k--;
            ll sum = it.pref[k];
            ll bad = 0;
            k /= 2;
            k--;
            if(k >= 0){
                bad = it.pref[k];
            }
            cout << sum - 2LL * bad << ' ';
        }
        cout << '\n';
    }
    return 0;
}

//TLE Code 
