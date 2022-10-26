#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 501;
vector<int> par(N);
int n, m;

int bfs(vector<vector<int>> &cap, int s, int t){
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
int Max_flow(vector<vector<int>> &res, int s, int t){
    int flow = 0, new_flow;
    new_flow = bfs(res, s, t);
    while(new_flow){
        flow += new_flow;
        int cur = t;
        while(cur != s){
            int prev = par[cur];
            res[prev][cur] -= new_flow;
            res[cur][prev] += new_flow;
            cur = prev;
        }
        new_flow = bfs(res, s, t);
    }
    return flow;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int> (n + 1, 0)), res (n + 1, vector<int> (n + 1, 0));
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a][b]++;
        g[b][a]++;
        res[a][b]++;
        res[b][a]++;
    }
    Max_flow(res, 0, n - 1);
     vector<pair<int, int>> ans;
     for(int i = 0; i < n; i++){
         for(int j = 0; j < n; j++){
             if(!res[i][j] and par[i] != - 1 and par[j] == -1 and g[i][j]){
                 ans.emplace_back(i, j);
             }
         }
     }
     cout << ans.size() << '\n';
     for(auto x : ans){
         cout << x.first + 1 << ' ' << x.second + 1 << '\n';
     }
    return 0;
}
