#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define  int long long
const int MOD = 998244353;

int bin(int x, int y){
    int ans = 1;
    while (y){
        if(y & 1)ans = ans * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return ans;
}

class DSU{
public:
    vector<int> P, SZ;
    void init(int n){
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

        if(SZ[u] > SZ[v]){
            swap(u, v);
        }
        P[v] = u;
        SZ[u] += SZ[v];
    }
}DS;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n, s;
        cin >> n >> s;
        vector<pair<int, pair<int, int>>> edge;
        for (int i = 1; i < n; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edge.push_back({w, {u, v}});
        }
        sort(edge.begin(), edge.end());
        DS.init(n + 2);
        int ans = 1;
        for (auto x: edge) {
            int u = x.second.first;
            int v = x.second.second;
            int w = x.first;
            if (DS.FIND(u) != DS.FIND(v)) {
                int c1 = DS.SZ[DS.FIND(u)];
                int c2 = DS.SZ[DS.FIND(v)];
                ans = ans * bin(s - w + 1, (c1 * c2 - 1)) % MOD;
                DS.UNION(u, v);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
