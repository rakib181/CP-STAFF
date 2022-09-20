#include<bits/stdc++.h>
using namespace std;

const int N = 30000;
vector<pair<int, int>> g[N];
vector<int> dist(N, 0);
vector<bool> vis(N, false);

void reset(int n){
   for(int i = 0; i < n; i++){
     dist[i] = 0;
     vis[i] = false;
   }
}

void bfs(int cur){
  queue<int> q;
  q.push(cur);
  vis[cur] = true;

  while(!q.empty()){
    int node = q.front();
    q.pop();

    for(auto x : g[node]){
       if(!vis[x.first]){
        vis[x.first] = true;
         dist[x.first] = dist[node] + x.second;
         q.push(x.first);
       }
    }
  }
}


int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0); 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    #endif
    auto start=clock();
    int tt, idx = 1;
    cin >> tt;
    while(tt--){
    cout << "Case " << idx++ << ": ";
    int n;
    cin >> n;
    reset(n);
    for(int i = 0; i < n; i++){
      g[i].clear();
    }
    for(int i = 0; i < n - 1; i++){
      int u, v, wt;
      cin >> u >> v >> wt;
       g[u].push_back({v, wt});
       g[v].push_back({u, wt});
    }
    bfs(0);
    int mx = INT_MIN, node = 0;
    for(int i = 0; i < n; i++){
        if(dist[i] > mx){
          mx = dist[i];
          node = i;
        }
    }
    reset(n);
    bfs(node);
    int ans = 0;
    for(int i = 0; i < n; i++){
      if(dist[i] > ans){
        ans = dist[i];
      }
    }
    cout << ans << '\n';
    }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
