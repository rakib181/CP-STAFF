#include <bits/stdc++.h>
using namespace std;

#define long long long

class DSU{
public:
    vector<int> P, SZ;
    void INIT(int n){
        P.assign(n, 0);
        SZ.assign(n, 1);
        iota(P.begin(), P.end(), 0);
    }

    int FIND(int v){
        if(P[v] == v)return v;
        return P[v] = FIND(P[v]);
    }

    void UNION(int u, int v){
        u = FIND(u), v = FIND(v);
        if(u == v)return;
        SZ[u] += SZ[v];
        P[v] = u;
    }
}dsu;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    dsu.INIT(n + 2);
    vector<int> col(n + 2, 0), cnt(n + 2, 1);
    iota(col.begin(), col.end(), 0);
    while (q--){
        int type;
        cin >> type;
        if(type == 1){
            int x, c;
            cin >> x >> c;
            x--, c--;
            int l = dsu.FIND(x);
            int sz = dsu.SZ[dsu.FIND(x)];
            int r = l + sz;
            cnt[col[l]] -= (r - l);
            col[l] = c;
            cnt[col[l]] += (r - l);
            while (l){
                if(col[dsu.FIND(l - 1)] != c)break;
                dsu.UNION(l - 1, l);
                l = dsu.FIND(l);
            }
            while (r != n){
                if(col[dsu.FIND(r)] != c)break;
                dsu.UNION(r - 1, r);
                r = dsu.FIND(l) + dsu.SZ[dsu.FIND(l)];
            }
        }else{
            int c;
            cin >> c;
            c--;
            cout << cnt[c] << '\n';
        }
    }
    return 0;
}
