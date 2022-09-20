#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
vector<pair<int, int>> tme_io(N);
vector<bool> vis(N, false);
vector<int> flat(N, 0);
int tme = 1;

// 1. Euler Tour
void dfs1(int cur){
   vis[cur] = true;
   //When I Enter A Node I Print It
   tme_io[cur].first = tme++;
   cout << cur << ' ';
   for(auto x : g[cur]){
    if(!vis[x]){
      dfs1(x);
    }
   }
   //When I Exit A Node I Print It
   tme_io[cur].second = tme++;
   cout << cur << ' ';
}

//2. Euler Tour
void dfs2(int cur){
  vis[cur] = true;
  //When I Enter A Node I Print It
  tme_io[cur].first = tme++;
  cout << cur << ' ';

  for(auto x : g[cur]){
    if(!vis[x]){
      dfs2(x);
      //When I Return Back To Node I Print It
      tme_io[cur].second = tme++;
      cout << cur << ' ';
    }
  }
}

//3. Euler Tour
void dfs3(int cur){
  vis[cur] = true;
  //When I Come To A Node I Increment It's Timein
  tme_io[cur].first = ++tme;
  for(auto x : g[cur]){
    if(!vis[x]){
      dfs3(x);
    }
  }
  //When I Leave A Node I Won't Increment It's Value
  tme_io[cur].second = tme;
}

int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0); 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    #endif
    auto start=clock();
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    //dfs1(1);
    tme = 0;
    dfs3(1);
    cout << '\n';
    for(int i = 1; i <= n; i++){
      cout << i << ' ' <<  tme_io[i].first << ' ' << tme_io[i].second << '\n';
    }
    for(int i = 1; i <= n; i++){
      flat[tme_io[i].first] = i;
    }
    // Flating Depending Intime Of A Node
    for(int i = 1; i <= n; i++){
      cout << flat[i] << ' ';
    }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
