#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 9;
const ll inf = 1e8 + 9;
int a[N];
ll t[4 * N], p[N];

void upd(int node, int b, int e, int i, ll v){
    if(b > i or e < i)return;
    if(b == e){
        t[node] = v;
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * node, b, m, i, v);
    upd(2 * node + 1, m + 1, e, i, v);
    t[node] = min(t[2 * node], t[2 * node + 1]);
}

ll query(int node, int b, int e, int l, int r){
    if(b > r or e < l)return inf;
    if(b >= l and e <= r)return t[node];
    int m = (b + e) >> 1;
    return min(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 0; i <= n; i++){
            p[i] = 0;
        }
        for(int i = 1; i <= 4 * n; i++){
            t[i] = inf;
        }
        map<int, vector<int>> mp;
        for(int i = 1; i <= n; i++){
            p[i] = p[i - 1] + a[i];
            upd(1, 1, n, i, p[i] - a[i]);
            mp[a[i]].emplace_back(i);
        }
        if((int) mp.size() == 1){
            cout << "Not Possible\n";
            continue;
        }
        ll ans = -inf;
        for(auto [x, v] : mp){
            int len = (int) v.size();
            for(int i = 0; i < len; i++){
                ans = max(ans, p[v[i]] - query(1, 1, n, 1, v[i] - 1));
                upd(1, 1, n, v[i], inf);
            }
            for(int i = 0; i < len; i++){
                upd(1, 1, n, v[i], p[v[i]] - a[v[i]]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
