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
}DS;

int fun(pair<int, int> &x, pair<int, int> &y){
     int x1 = abs(x.first - y.first), y1 = abs(x.second - y.second);
     x1 *= x1, y1 *= y1;
     int tot = x1 + y1;
    return tot;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--){
        int n, r;
        cin >> n >> r;
        DS.init(n + 2);
        vector<pair<int, int>> coordinate(n);
        for(int i = 0; i < n; i++){
            cin >> coordinate[i].first >> coordinate[i].second;
        }
        vector<pair<double, pair<int, int>>> edges;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                edges.push_back({fun(coordinate[i], coordinate[j]), {i, j}});
            }
        }
        sort(edges.begin(), edges.end());
        int state = 1; double mnRoad = 0, mnRail = 0;
        for(auto x : edges){
            int u = x.second.first, v = x.second.second; double c = x.first;
            if(DS.FIND(u) != DS.FIND(v)){
                DS.UNION(u, v);
                if(c <= r * r){
                    mnRoad += sqrt(c);
                }else{
                    state++;
                    mnRail += sqrt(c);
                }
            }
        }
        cout << "Case #" << cs++ << ": " << state << ' ' << (int) round(mnRoad) << ' ' << (int) round(mnRail) << '\n';
    }
    return 0;
}
