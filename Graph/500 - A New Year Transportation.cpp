#include<bits/stdc++.h>
using namespace std;

const int N = 3e4 + 9;
vector<int> g[N];
vector<bool> vis(N, false);

void dfs(int cur){
    vis[cur] = true;
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
      int n, t;
      cin >> n >> t;
      vector<int> ar(n + 1);
      for(int i = 1; i <= n; i++){
         cin >> ar[i];
         g[i].push_back(i + ar[i]);
      }
      dfs(1);
      if(vis[t])cout << "YES" << '\n';
      else cout << "NO" << '\n';
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
