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
}DS, DS1;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, idx = 1;
    cin >> tt;
    while (tt--) {
        cout << "Case " << idx++ << ": ";
        int n, tot = 0;
        cin >> n;
        DS.init(n + 5);
        DS1.init(n + 5);
        vector<pair<int, pair<int, int>>> a;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int wt;
                cin >> wt;
                tot += wt;
               if(wt) a.push_back({wt, {i, j}}),DS1.UNION(i, j);
            }
        }
        sort(a.begin(), a.end());
        int ii = DS1.FIND(1); bool ok = true;
        for(int i = 1; i <= n; i++){
            if(DS1.FIND(i) != ii){
                ok = false;
                break;
            }
        }
        if(ok){
            cout << tot - DS.MST(a) << '\n';
        }else cout << "-1" << '\n';
    }
    return 0;
}
