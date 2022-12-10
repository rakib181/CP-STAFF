#include<bits/stdc++.h>
using namespace std;

class DSU{
public:
    vector<int> P, SZ, CNT;
    void init(int n){
        P.resize(n);
        SZ.resize(n, 1);
        CNT.resize(n, 0);
        iota(P.begin(), P.end(), 0);
    }

    int FIND(int v){
        if(P[v] == v)return v;
        return P[v] = FIND(P[v]);
    }

    void UNION(int u, int v){
        CNT[u]++, CNT[v]++;
        u = FIND(u), v = FIND(v);
        if(u == v)return;

        if(SZ[u] > SZ[v]){
            swap(u, v);
        }
        P[v] = u;
        SZ[u] += SZ[v];
    }
}DS;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        DS.init(2 * n + 9);
        for(int i = 1; i <= n; i++){
            int u, v;
            cin >> u >> v;
            DS.UNION(u + n, v), DS.UNION(u, v + n);

        }
        bool ok = true;
        for(int i = 1; i <= n; i++){
            if(DS.FIND(i) == DS.FIND(i + n) or DS.CNT[i] > 2){
                ok = false;
                break;
            }
        }
        if(ok)cout << "YES" << '\n';
        else cout << "NO" << '\n';
        DS.SZ.clear(), DS.P.clear(), DS.CNT.clear();
    }
    return 0;
}
