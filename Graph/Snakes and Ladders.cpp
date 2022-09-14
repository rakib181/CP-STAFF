#include<bits/stdc++.h>
using namespace std;

int min_bfs(vector<int> g[], int src, int des, int n){
    vector<int> dist(n + 1, 0);
    vector<bool> vis(n + 1, false);
    queue<int> q;
    q.push(src);
    vis[src] = true;
    dist[src] = 0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto x : g[cur]){
            if(!vis[x]){
                vis[x] = true;
                dist[x] = dist[cur] + 1;
                q.push(x);
            }
        }
    }
    return dist[des];
}


int min_dice_throws(int n,vector<pair<int,int> > snakes, vector<pair<int,int> > ladders){
    vector<int> board(n + 1, 0);
    for(auto x : snakes){
        int pos = x.second - x.first;
        board[x.first] = pos; 
    }
     for(auto x : ladders){
        int pos = x.second - x.first;
        board[x.first] = pos; 
    }
    vector<int> g[n + 1];
    for(int i = 1; i < n; i++){
         for(int j = 1; j <= 6; j++){
            int v = j + i;
            v += board[v];
            if(v <= n){
                g[i].push_back(v);
            }
         }
    }
    
    return min_bfs(g, 1, n, n);
}
