#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;

int bfs(vector<vector<int>> &cap, int s, int t, vector<int> &par){
    queue<pair<int, int>> q;
    q.push({s, INT_MAX});
    par.assign(n, -1);
    par[s] = -2;
    while(!q.empty()){
        int node = q.front().first;
        int flow = q.front().second;
        q.pop();
        for(int i = 0; i < n; i++){
            if(par[i] == -1 and cap[node][i]){
                par[i] = node;
                int new_flow = min<long long>(flow, cap[node][i]);
                if(i == t)return new_flow;
                q.push({i, new_flow});
            }
        }
    }
    return 0;
}
int Max_flow(vector<vector<int>> &graph, int s, int t){
    vector<int> parent;
    int flow = 0, new_flow;
    vector<vector<int>> res = graph;
    new_flow = bfs(res, s, t, parent);
    while(new_flow){
        flow += new_flow;
        int cur = t;
        while(cur != s){
            int prev = parent[cur];
            res[prev][cur] -= new_flow;
            res[cur][prev] += new_flow;
            cur = prev;
        }
        new_flow = bfs(res, s, t, parent);
    }
    return flow;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int> (n + 1, 0));
    for(int i = 0; i < m; i++){
        int a, b, wt;
        cin >> a >> b >> wt;
        --a, --b;
        g[a][b] += wt;
    }
    cout << Max_flow(g, 0, n - 1) << '\n';
    return 0;
}
