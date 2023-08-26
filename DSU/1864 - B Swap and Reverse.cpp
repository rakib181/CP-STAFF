#include <bits/stdc++.h>
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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
       int n, k;
       cin >> n >> k;
       string s;
       cin >> s;
       s = '&' + s;
       DS.init(n + 5);
       multiset<char> c[n + 1];
       for(int i = 1; i <= n; i++){
           if(i + 2 <= n and DS.FIND(i) != DS.FIND(i + 2)){
               DS.UNION(i, i + 2);
               int idx = DS.FIND(i);
           }
           if(i + k - 1 <= n and DS.FIND(i) != DS.FIND(i + k - 1)){
               DS.UNION(i, i + k - 1);
               int idx = DS.FIND(i);
           }
       }
       for(int i = 1; i <= n; i++){
           c[DS.FIND(i)].insert(s[i]);
       }
       string ans;
       for(int i = 1; i <= n; i++){
           ans += (*c[DS.FIND(i)].begin());
           c[DS.FIND(i)].erase(c[DS.FIND(i)].begin());
       }
       cout << ans << '\n';
    }
    return 0;
}
