#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;

int pow(int a, int b){
    int ans = 1LL;
    while(b){
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1LL;
    }
    return ans;
}

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
    int n, k, ans;
    cin >> n >> k;
    ans = pow(n, k);
    DS.init(n + 5);
    for(int i = 1; i < n; i++){
        int u, v, x;
        cin >> u >> v >> x;
        if(!x)DS.UNION(u, v);
    }
    for(int i = 1; i <= n; i++){
        int cc = DS.FIND(i);
       if(cc == i) ans -= pow(DS.SZ[cc], k),ans = (ans + mod) % mod;
    }
    cout << ans << '\n';
    return 0;
}
