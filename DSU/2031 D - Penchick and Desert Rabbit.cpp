#include <bits/stdc++.h>
using namespace std;

#define long long long

class DSU{
public:
    vector<int> P, SZ;
    void INIT(int n){
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
}dsu;

const int inf = 1e9 + 7;


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++)cin >> a[i];
        dsu.INIT(n + 5);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for(int i = n; i >= 1; i--){
            pair<int, int> cur = {a[i], i};
            while (!pq.empty()){
                auto [v, j] = pq.top();
                if(v >= a[i])break;
                pq.pop();
                dsu.UNION(i, j);
                cur = min(cur, make_pair(v, j));
            }
            pq.push(cur);
        }
        vector<int> mx(n + 1, 0);
        for(int i = 1; i <= n; i++){
            int f = dsu.FIND(i);
            mx[f] = max(mx[f], a[i]);
        }
        for(int i = 1; i <= n; i++){
            cout << mx[dsu.FIND(i)] << " \n"[i == n];
        }
    }
    return 0;
}
