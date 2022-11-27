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

    int MST(vector<pair<int, pair<int, int>>> &a){
         int tot = 0;
         for(auto x : a){
             int wt = x.first, u = x.second.first, v = x.second.second;
             if(FIND(u) != FIND(v)){
                 tot += wt;
                 UNION(u, v);
             }
         }
        return tot;
    }
}DS1, DS2;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, idx = 1;
    cin >> tt;
    while (tt--) {
        cout << "Case " << idx++ << ": ";
        int n;
        cin >> n;
        DS1.init(n + 10);
        DS2.init(n + 10);
        vector<pair<int, pair<int, int>>> a, aa;
        while (true) {
            int u, v, wt;
            cin >> u >> v >> wt;
            if(u == 0 and v == 0 and wt == 0)break;
            a.push_back({wt, {u, v}});
            aa.push_back({wt, {u, v}});
        }
        sort(a.begin(), a.end());
        sort(aa.rbegin(), aa.rend());
        int tot = DS1.MST(aa);
        tot += DS2.MST(a);
        if (tot % 2 == 0) {
            cout << tot / 2 << '\n';
        } else cout << tot << "/" << "2" << '\n';
        a.clear();
        aa.clear();
    }
    return 0;
}
