#include<bits/stdc++.h>
using namespace std;
#define int long long

struct MST{
    vector<vector<int>> t;
    vector<vector<int>> s;
    vector<int> a;
    MST(vector<int> &a, int n){
        this -> a.resize(n + 1);
        this -> s.assign(4 * n + 1, vector<int> ());
        t.assign(4 * n + 1, vector<int> ());
        for(int i = 1; i <= n; i++){
            this -> a[i] = a[i];
        }
    }
    void build(int node, int b, int e){
        if(b == e){
            t[node].emplace_back(a[b]);
            s[node].emplace_back(a[b]);
            return;
        }
        int m = (b + e) >> 1;
        build(2 * node, b, m);
        build(2 * node + 1, m + 1, e);
        int i = 0, j = 0, sz_l = (int) t[2 * node].size() - 1, sz_r = (int) t[2 * node + 1].size() - 1;
        while(i <= sz_l and j <= sz_r){
            if(t[2 * node][i] > t[2 * node + 1][j]) {
                t[node].emplace_back(t[2 * node + 1][j++]);
            }else t[node].emplace_back(t[2 * node][i++]);
        }
        while(i <= sz_l)t[node].emplace_back(t[2 * node][i++]);
        while(j <= sz_r)t[node].emplace_back(t[2 * node + 1][j++]);
        int sz = (int) t[node].size();
        s[node].assign(sz, 0);
        for(i = 0; i < sz; i++){
            s[node][i] = t[node][i];
            if(i)s[node][i] += s[node][i - 1];
        }
    }

    int query(int node, int b, int e, int l, int r, int x){
        if(b > r or e < l)return 0;
        if(b >= l and e <= r){
            int idx_l = -1, idx_r = -1;
            int count = 0;
            {
                int L = 0, R = (int) t[node].size() - 1;
                while(L <= R){
                    int M = (L + R) >> 1;
                    if(t[node][M] < x){
                        idx_l = M;
                        L = M + 1;
                    }else R = M - 1;
                }
                if(idx_l != -1){
                    count += abs(s[node][idx_l] - (1LL * x * (idx_l + 1)));
                }
            }
            {
                int L = 0, R = (int) t[node].size() - 1;
                while(L <= R){
                    int M = (L + R) >> 1;
                    if(t[node][M] > x){
                        idx_r = M;
                        R = M - 1;
                    }else L = M + 1;
                }
                if(idx_r != -1){
                    int sz = (int) t[node].size();
                    count += abs((1LL * (sz - idx_r) * x) - (s[node][sz - 1] - (idx_r ? s[node][idx_r - 1] : 0)));
                }
            }
            return count;
        }
        int m = (b + e) >> 1;
        return query(2 * node, b, m, l, r, x) + query(2 * node + 1, m + 1, e, l, r, x);
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, cs = 1;
    cin >> t;
    while(t--){
        cout << "Case " << cs++ << ":\n";
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++)cin >> a[i];
        MST ms(a, n);
        ms.build(1, 1, n);
        int q;
        cin >> q;
        while(q--){
            int l, r, x;
            cin >> l >> r >> x;
            cout << ms.query(1, 1, n, l, r, x) << '\n';
        }
    }
    return 0;
}
