#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        int n, root, pre = -1;
        cin >> n;
        vector<int> g[n + 1];
        cin >> root;
        queue<int> b_t;
        for(int i = 0; i < n - 1; i++){
            int x;
            cin >> x;
            if(x < pre){
                root = b_t.front();
                b_t.pop();
            }
            g[root].push_back(x);
            b_t.push(x);
            pre = x;
        }
        vector<int> dist(n + 1, INT_MAX);
        queue<int> q;
        q.push(1);
        dist[1] = 0;
        while (!q.empty()){
            auto it = q.front();
            q.pop();
            for(auto x : g[it]){
                if(dist[x] == INT_MAX){
                    dist[x] = dist[it] + 1;
                    q.push(x);
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans = max(ans, dist[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}
