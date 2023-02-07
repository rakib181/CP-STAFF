#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e6 + 9, MX = 1005;
vector<vector<bool>> mark(MX, vector<bool> (MX, false));
vector<vector<int>> ids(MX, vector<int> (MX));
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

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

    void UNION(int u, int v, int &cc){
        u = FIND(u), v = FIND(v);
        if(u == v)return;
        cc--;
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
    int n, m, q, assign = 1;
    cin >> n >> m >> q; DS.init(n * m + 10);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            ids[i][j] = assign++;
        }
    }
    auto valid = [&](int x, int y){
        return x > 0 and x <= n and y > 0 and y <= m and mark[x][y];
    };
    int cc = 0;
    while (q--){
        int type;
        cin >> type;
        if(type){
            int x, y;
            cin >> x >> y;
            if(!mark[x][y])cc++;
            mark[x][y] = true;
            for(int i = 0; i < 4; i++){
                int xx = x + dx[i], yy = y + dy[i];
                if(valid(xx, yy)){
                    DS.UNION(ids[x][y], ids[xx][yy], cc);
                }
            }

        }else cout << cc << '\n';
    }
    return 0;
}
