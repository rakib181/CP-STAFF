#include<bits/stdc++.h>
using namespace std;

bool bfs(map<int, set<int>> &g, int n){
    queue<int> q;
    map<int, bool> vis;
    q.push(0);
    vis[0] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto x : g[node]){
            if(!vis[x]){
                vis[x] = true;
                q.push(x);
            }
        }
    }
    return vis.size() == n;
}

bool solve(int n, vector<vector<int>> roads) {
    map<int, set<int>> g;
    for(int i = 0; i < roads.size(); i++){
        g[roads[i][0]].insert(roads[i][1]);
    }
    bool all_tog = bfs(g, n);
    if(!all_tog)return false;

    map<int, set<int>> gr;
    for(auto x : g){
        for(auto y : x.second){
            gr[y].insert(x.first);
        }
    }
    all_tog = bfs(gr, n);
    return all_tog;
}

int main(){
    int n = 2;
    vector<vector<int>> roads = {
        {0, 1}, {1, 0}
    };
    cout << solve(n, roads) << '\n';
}
