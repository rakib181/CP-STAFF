#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
vector<int> g[N];
int ind[N];


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while(cin >> n >> m and !(n == 0 and m == 0)) {
        for(int i = 1; i <= n; i++){
            g[i].clear();
            ind[i] = 0;
        }
        for(int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
            ind[v] += 1;
        }
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (!ind[i])q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << ' ';
            for (auto x: g[node]) {
                if (--ind[x] == 0) {
                    q.push(x);
                }
            }
        }
        cout << '\n';
    }
    return 0;
}
