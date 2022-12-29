#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e15;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int cs = 1; bool ok = true;
    while (true) {
        int n, m, q;
        cin >> n >> m >> q;
        if(!n)break;
        vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, INF));
        for (int i = 1; i <= n; i++) {
            dist[i][i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int u, v, wt;
            cin >> u >> v >> wt;
            if (dist[u][v] > wt) {
                dist[u][v] = wt;
                dist[v][u] = wt;
            }
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    long long cur = max(dist[i][k], dist[k][j]);
                    if (cur < dist[i][j]) {
                        dist[i][j] = cur;
                        dist[j][i] = cur;
                    }
                }
            }
        }
        if(!ok){
            cout << '\n';
        }
        ok = false;
        cout << "Case #" << cs++ <<'\n';
        while (q--) {
            int src, dest;
            cin >> src >> dest;
            if (dist[src][dest] == INF)cout<< "no path" << '\n';
            else cout << dist[src][dest] << '\n';
        }
    }
    return 0;
}
