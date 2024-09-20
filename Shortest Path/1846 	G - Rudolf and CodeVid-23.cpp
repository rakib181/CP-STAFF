#include<bits/stdc++.h>
using namespace std;
#define long long long

const int N = (1 << 10) + 1, M = 1005, inf = 1e9 + 7;
int n, m;
vector<pair<int, pair<string, string>>> a( M);

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        string s;
        cin >> s;
        int source = 0;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '1'){
                source |= (1 << i);
            }
        }
        vector<pair<pair<int, int>, int>> edges(m);
        auto get_mask = [&](string &x){
              int msk = 0;
             for(int j = n - 1; j >= 0; j--){
                 if(x[j] == '1'){
                     msk |= (1 << j);
                 }
             }
            return msk;
        };
        for(int i = 0; i < m; i++){
            cin >> edges[i].second;
            string x, y;
            cin >> x >> y;
            int u = get_mask(x), v = get_mask(y);
            edges[i].first.first = u, edges[i].first.second = v;
        }
        vector<int> dist(1 << n, inf);
        dist[source] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, source);
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int u = it.second;
            for(int i = 0; i < m; i++){
                int msk = u;
                for(int j = n - 1; j >= 0; j--){
                    if((edges[i].first.first >> j & 1) and (msk >> j & 1)){
                        msk ^= (1 << j);
                    }
                    if((edges[i].first.second >> j & 1)){
                        msk |= (1 << j);
                    }
                }
                if(dist[u] + edges[i].second < dist[msk]){
                    dist[msk] = dist[u] + edges[i].second;
                    pq.emplace(dist[msk], msk);
                }
            }
        }
        int ans = dist[0];
        cout << (ans == inf ? -1 : ans) << '\n';
    }
    return 0;
}
