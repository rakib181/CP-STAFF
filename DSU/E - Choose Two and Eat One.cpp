#include <bits/stdc++.h>
using namespace std;
#define int long long int


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

int bin(int x, int y, int mod){
    int ans = 1;
    while (y){
        if(y & 1)ans = ans * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ans;
}

int func(int x, int y, int m){
    return (bin(x, y, m) + bin(y, x, m)) % m;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,  m;
    cin >> n >> m;
    DS.init(n + 10);
    vector<int> ar(n);
    for(int i = 0; i < n; i++)cin >> ar[i];
    vector<pair<int, pair<int, int>>> edges;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
           edges.push_back({func(ar[i], ar[j], m), {i, j}});
        }
    }
    sort(edges.rbegin(), edges.rend());
    int ans = 0;
    for(auto x : edges){
        int cost = x.first, u = x.second.first, v = x.second.second;
        if(DS.FIND(u) != DS.FIND(v)){
            ans += cost;
            DS.UNION(u, v);
        }
    }
    cout << ans << '\n';
    return 0;
}
