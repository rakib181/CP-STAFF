#include<bits/stdc++.h>
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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        DS.init(n + 2);
        for(int i = 0; i < n; i++){
            if(i < n - i - 1){
                DS.UNION(i, n - i - 1);
            }
            if(i + k < n){
                DS.UNION(i, i + k);
            }
        }
        vector<int> comp[n + 1];
        for(int i = 0; i < n; i++){
           comp[DS.FIND(i)].push_back(i);
        }
        int ans = n, no_need = 0;
        for(int i = 0; i < n; i++){
            vector<int> cnt(26, 0);
            for(int x : comp[i]){
                cnt[s[x] - 'a']++;
            }
            no_need += *max_element(cnt.begin(), cnt.end());
        }
        cout << ans - no_need << '\n';
        DS.P.clear(), DS.SZ.clear();
    }
    return 0;
}
