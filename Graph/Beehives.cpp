#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 505;
vector<int> g[N];
vector<int> dis(N), par(N);
int ans;

void CLR(){
   for(int i = 0; i < N; i++){
       dis[i] = -1;
       par[i] = -1;
   }
}

void BFS(int src){
    queue<int> q;
    q.push(src);
    dis[src] = 0;
    while (!q.empty()){
        int node  = q.front();
        q.pop();
        for(auto x : g[node]){
            if(dis[x] == -1){
                dis[x] = dis[node] + 1;
                par[x] = node;
                q.push(x);
            }else if (x != par[node]){
                ans = min(ans, dis[node] + dis[x] + 1);
            }
        }
    }
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--) {
        cout << "Case " << cs++ << ": ";
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++)g[i].clear();
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ans = INT_MAX;
        for(int i = 0; i < n; i++){
                CLR();
                BFS(i);
        }
        if(ans == INT_MAX){
            cout << "Impossible" << '\n';
        }else cout << ans << '\n';

    }
    return 0;
}
