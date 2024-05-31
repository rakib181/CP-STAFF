#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 9, inf = 1e9 + 7;
int n, p[N], t[4 * N];
string s;

void build(int node, int b, int e){
    if(b == e){
        t[node] = p[b];
        return;
    }
    int m = (b + e) >> 1;
    build(2 * node, b, m);
    build(2 * node + 1, m + 1, e);
    t[node] = max(t[2 * node], t[2 * node + 1]);
}

int query(int node, int b, int e, int l, int r){
    if(b > r or e < l)return -inf;
    if(b >= l and e <= r)return t[node];
    int m = (b + e) >> 1;
    return max(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        cin >> s;
        n = (int) s.size();
        s = "$" + s;
        for(int i = 0; i <= 4 * n; i++){
            t[i] = -inf;
        }
        for(int i = 1; i <= n; i++){
            p[i] = p[i - 1] + (s[i] == '(' ? 1 : -1);
        }
        vector<int> id[n + 1];
        for(int i = 0; i <= n; i++){
            id[p[i]].emplace_back(i);
        }
        build(1, 0, n);
        ll ans = 0;
        for(int r = 0; r <= n; r++){
            vector<int> &v = id[r];
            int cnt = 0;
            for(int i = 1; i < (int) v.size(); i++){
                int L = v[i - 1], R = v[i];
                if(query(1, 0, n, L, R) <= 2 * r){
                    cnt += 1;
                }else{
                    cnt = 0;
                }
                ans += cnt;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
