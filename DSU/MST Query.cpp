#include<bits/stdc++.h>
using namespace std;
using ll = long long;

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

    bool UNION(int u, int v){
        u = FIND(u), v = FIND(v);
        if(u == v)return false;

        if(SZ[u] > SZ[v]){
            swap(u, v);
        }
        P[v] = u;
        SZ[u] += SZ[v];
        return true;
    }
}DS[15];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= 10; i++){
        DS[i].init(n + 5);
    }
    vector<int> cnt(15, n);
    for(int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        for(int j = w; j <= 10; j++) {
            cnt[j] -= DS[j].UNION(u, v);
        }
    }
    while(q--){
        int u, v, w;
        cin >> u >> v >> w;
        for(int i = w; i <= 10; i++){
           cnt[i] -= DS[i].UNION(u, v);
        }
        int sz = n, ans = 0;
        for(int i = 1; i <= 10; i++){
            ans += i * (sz - cnt[i]);
            sz = cnt[i];
        }
        cout << ans << '\n';
    }
    return 0;
}
