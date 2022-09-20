#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
vector<int> ar(N);
vector<bool> vis(N, false);

long long dfs(int cur, long long ans){
  vis[cur] = true;
  for(auto x : g[cur]){
    if(!vis[x]){
     long long sub = dfs(x, ans);
     ans = min<long long> (ans, sub);
    }
  }
  ans = min<long long>(ans, ar[cur]);
  return ans;
}

int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0); 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    #endif
    auto start=clock();
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
      cin >> ar[i];
    }
    for(int i = 0; i < q; i++){
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    long long tot = 0;
    for(int i = 1; i <= n; i++){
     long long ans = LONG_LONG_MAX;
      if(!vis[i]){
        int ok = dfs(i, ans);
        tot += ok;
      }
    }
    cout << tot << '\n';
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
