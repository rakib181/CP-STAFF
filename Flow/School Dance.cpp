#include <bits/stdc++.h>
using namespace std;
#define int long long
const int NN = 1500;
vector<int> par(NN);
int n, m, k;

int bfs(vector<vector<int>> &cap, int s, int t){
    queue<pair<int, int>> q;
    q.push({s, INT_MAX});
    par.assign(NN * NN, -1);
    par[s] = -2;
    while(!q.empty()){
        int node = q.front().first;
        int flow = q.front().second;
        q.pop();
        for(int i = 0; i < NN; i++){
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
            //cout << prev << ' ' << cur << '\n';
            cur = prev;
        }
        new_flow = bfs(res, s, t);
    }
    return flow;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    vector<vector<int>> g(NN, vector<int> (NN, 0)), res (NN, vector<int> (NN, 0));
    int source = 1401 , sink = source + 1;
    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        g[source][19 + a] = 1;
        g[19 + a][617 + b] = 1;
        g[617 + b][sink] = 1;
        res[source][19 + a] = 1;
        res[19 + a][617 + b] = 1;
        res[617 + b][sink] = 1;
    }
    Max_flow(res, source, sink);
    vector<pair<int, int>> ans;
    for(int i = 1; i < NN; i++){
        for(int j = 1; j < NN; j++){
            if(i != source and j != sink and !res[i][j] and g[i][j]){
                ans.emplace_back(i - 19, j - 617);
            }
        }
    }
    cout << ans.size() << '\n';
    for(auto x : ans){
        cout << x.first << ' ' << x.second << '\n';
    }
    return 0;
}
