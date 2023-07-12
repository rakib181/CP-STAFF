#include<bits/stdc++.h>
using namespace std;
using ll = long long;

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

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    map<ll, int> idx;
    DS.init(n + 2);
    for(int i = 1; i <= n; i++){
         int x;
         cin >> x;
         idx[x] = i;
    }
    for(auto x : idx){
        ll nxt = x.first * k;
        if(idx.count(nxt)){
            DS.UNION(idx[nxt], x.second);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(DS.FIND(i) == i){
            ans += (DS.SZ[DS.FIND(i)] + 1) / 2;
        }
    }
    cout << ans << '\n';
    return 0;
}
