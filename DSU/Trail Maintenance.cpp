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
    int MST(vector<pair<int, pair<int, int>>> &edges, int n){
        int tot = 0, cnt = 0;
        sort(edges.begin(), edges.end());
        vector<pair<int, pair<int, int>>> tmp;
        for(auto x : edges){
            int u = x.second.first, v = x.second.second, wt = x.first;
            if(FIND(u) != FIND(v)){
                cnt++;
                tot += wt;
                tmp.push_back(x);
                UNION(u, v);
            }
            if(cnt == n - 1)break;
        }
        edges.clear();
        edges = tmp;
        if(cnt == n - 1) return tot;
        else return -1;
    }
}DS;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, idx = 1;
    cin >> tt;
    while (tt--) {
        cout << "Case " << idx++ << ":\n";
        int n, m;
        cin >> n >> m;
        vector<pair<int, pair<int, int>>> edges;
        for(int i = 0; i < m; i++){
            int u, v, wt;
            cin >> u >> v >> wt;
            edges.push_back({wt, {u, v}});
            DS.init(n + 2);
            cout << DS.MST(edges, n) << '\n';
        }
        edges.clear();
    }
    return 0;
}
