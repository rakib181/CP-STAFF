#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<int> g[N];
vector<bool> vis(N, false);
vector<int> cnt_city(N, 0);

void reset(int n){
  for(int i = 1; i <= n; i++){
    vis[i] = false;
  }
}

void dfs(int cur){
  vis[cur] = true;
  ++cnt_city[cur];
  for(auto x : g[cur]){
    if(!vis[x]){
      dfs(x);
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
    int k, n, m;
    cin >> k >> n >> m;
    for(int i = 1; i <= n; i++)g[i].clear(), cnt_city[i] = 0;
    set<int> s;
    for(int i = 0; i < k; i++){
      int x;
      cin >> x;
      s.insert(x);
    }
    for(int i = 0; i < m; i++){
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
    }

    for(auto it = s.begin(); it != s.end(); it++){
      reset(n);
      dfs(*it);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
      if(cnt_city[i] == s.size())cnt++;
    }
    cout << cnt << '\n';
  }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
