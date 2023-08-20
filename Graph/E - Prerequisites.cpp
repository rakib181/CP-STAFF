#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
vector<int> g[N];
int n, ind[N];

vector<int> top(){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(ind[i] == 0) q.push(i);
    }
    vector<int> nodes;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        nodes.emplace_back(node);
        for(auto v : g[node]){
            if(--ind[v] == 0){
                q.push(v);
            }
        }
    }
    return nodes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int c;
        cin >> c;
        while(c--){
            int v;
            cin >> v;
            g[i].emplace_back(v);
            ind[v] += 1;
        }
    }
    vector<bool> vis(n + 1, false);
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto v: g[node]){
            if(!vis[v]){
                vis[v] = true;
                q.push(v);
            }
        }
    }
    vector<int> t = top();
    vector<int> order(n + 1);
    for(int i = 1; i <= n; i++){
        order[t[i - 1]] = i;
    }
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        if(vis[i])ans.emplace_back(i);
    }
    sort(ans.begin(), ans.end(), [&](int x, int y){
        return order[x] > order[y];
    });
    for(auto v: ans){
        cout << v << ' ';
    }
    return 0;
}
