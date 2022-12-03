#include<bits/stdc++.h>
using namespace std;

const int N = 105;
vector<int> g[N];

void BFS(int cur, vector<int> &dis, int n){
    queue<int> q;
    vector<int> vis(n, false);
    q.push(cur);
    dis[cur] = 0;
    vis[cur] = true;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        for(auto x: g[node]){
            if(!vis[x]){
                q.push(x);
                vis[x] = true;
                dis[x] = dis[node] + 1;
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
        int src, des, ans = 0;
        cin >> src >> des;
        vector<int> dis_from_src(n, -1);
        BFS(src, dis_from_src, n);
        vector<int> dis_from_des(n, -1);
        BFS(des, dis_from_des, n);
        for(int i = 0; i < n; i++){
            ans = max(ans, dis_from_src[i] + dis_from_des[i]);
        }
       cout << ans << '\n';
    }
    return 0;
}
