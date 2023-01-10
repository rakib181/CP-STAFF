#include<bits/stdc++.h>
using namespace std;

struct P{
    double x, y;
};

double func(P x, P y){
    return sqrt(pow(x.x - y.x, 2) + pow(x.y - y.y, 2));
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for(int ow = 1; ow <= tt; ow++){
        int n;
        cin >> n;
        DS.init(n + 10);
        vector<P> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i].x >> a[i].y;
        }
        vector<pair<double, pair<int, int>>> edges;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                edges.push_back({func(a[i], a[j]), {i, j}});
            }
        }
        sort(edges.begin(), edges.end());
        double ans = 0;
        for(auto x : edges){
            int u = x.second.first, v = x.second.second; double c = x.first;
            if(DS.FIND(u) != DS.FIND(v)){
                ans += c;
                DS.UNION(u, v);
            }
        }
        cout << fixed << setprecision(2) << ans << '\n';
        if(ow != tt){
            cout << '\n';
        }
    }
}
