#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
vector<int> depth(N, 0), height(N, 0);

void dfs(int cur, int par){
    for(auto x : g[cur]){
        if(x != par){
            depth[x] = depth[cur] + 1;
            dfs(x, cur);
            height[cur] = max(height[cur], height[x] + 1);
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
      int n;
      cin >> n;
      for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
      }
      dfs(1, 0);
      for(int i = 1; i <= n; i++){
        cout << depth[i] << ' ';
      }
      cout << '\n';
      for(int i = 1; i <= n; i++){
        cout << height[i] << ' ';
      }
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
