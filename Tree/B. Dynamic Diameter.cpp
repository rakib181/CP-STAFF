//BFS
#include<bits/stdc++.h>
using namespace std;
#define int long long int
int n;
const int N = 3e5 + 9;
vector<int> g[N]; int node;
vector<pair<int, bool>> dist(N);

void BFS(int cur){
    for(int i = 1; i <= n; i++){
        dist[i].first = -1;
    }
    dist[cur].first = 0;
    queue<int> q;
    q.push(cur);
    while (!q.empty()){
        int nod = q.front();
        q.pop();
        for(auto x : g[nod]){
            if(dist[x].first == -1){
                dist[x].first = dist[nod].first + 1;
                q.push(x);
            }
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    node = n;
    BFS(node);    int mx = dist[1].first;
    for(int i = 1; i < n; i++) {
        if(dist[i].first > mx){
            mx = dist[i].first;
            node = i;
        }
    }
    BFS(node);
    mx = dist[node].first;
    for(int i = 1; i <= n; i++){
        if(mx < dist[i].first){
           mx = dist[i].first;
           node = i;
        }
    }
    for(int i = 1; i <= n; i++){
        if(dist[i].first == mx){
            dist[i].second = true;
        }
    }
    BFS(node);
    for(int i = 1; i <= n; i++){
        if(dist[i].first == mx){
            dist[i].second = true;
        }
    }
    for(int i = 1; i <= n; i++){
        if(dist[i].second)cout << mx + 1 << '\n';
        else cout << mx << '\n';
    }
    return 0;
}
//DFS
#include<bits/stdc++.h>
using namespace std;
#define int long long int
int n;
const int N = 3e5 + 9;
vector<int> g[N]; int node;
vector<pair<int, bool>> dist(N);

void DFS(int cur, int par = -1){
    for(auto x : g[cur]){
        if(x != par){
            dist[x].first = dist[cur].first + 1;
            DFS(x, cur);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    node = n;
    DFS(node);    int mx = dist[1].first;
    for(int i = 1; i < n; i++) {
        if(dist[i].first > mx){
            mx = dist[i].first;
            node = i;
        }
        dist[i].first = 0;
    }
    DFS(node);
    mx = dist[node].first;
    for(int i = 1; i <= n; i++){
        if(mx < dist[i].first){
           mx = dist[i].first;
           node = i;
        }
    }
    for(int i = 1; i <= n; i++){
        if(dist[i].first == mx){
            dist[i].second = true;
        }
    }
    for(int i = 1; i <= n; i++){
        dist[i].first = 0;
    }
    DFS(node);
    for(int i = 1; i <= n; i++){
        if(dist[i].first == mx){
            dist[i].second = true;
        }
    }
    for(int i = 1; i <= n; i++){
        if(dist[i].second)cout << mx + 1 << '\n';
        else cout << mx << '\n';
    }
    return 0;
}
