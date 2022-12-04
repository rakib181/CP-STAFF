#include<bits/stdc++.h>
using namespace std;

class DSU{
public:
    vector<int> P, SZ;
    void init(int n){
        P.resize(n);
        SZ.resize(n, 1);
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


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, extra = 0;
    cin >> n >> m;
    DS.init(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        if(DS.FIND(u) != DS.FIND(v))  DS.UNION(u, v);
        else extra++;
        vector<int> a;
        for(int ii = 1; ii <= n; ii++){
           if(DS.FIND(ii) == ii) a.push_back(DS.SZ[DS.FIND(ii)]);
        }
        sort(a.rbegin(), a.rend());
        int ans = a[0];
        for(int iii = 1; iii <= extra; iii++){
            if(iii >= (int) a.size())break;
            ans += a[iii];
        }
        cout << ans - 1 << '\n';
    }
    return 0;
}
