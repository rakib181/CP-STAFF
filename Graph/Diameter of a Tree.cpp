#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
vector<int> depth(N, 0);

void dfs(int cur, int par){
    for(auto x : g[cur]){
        if(x != par){
            depth[x] = depth[cur] + 1;
            dfs(x, cur);
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
        g[v].push_back(u);
      }
      dfs(1, 0); int node = -1;
      for(int i = 1; i <= n; i++){
        if(node < depth[i])node = i;
        cout << depth[i] << ' ';
      }
      cout << '\n';
      for(int i = 0; i <= n; i++)depth[i] = 0;
      dfs(node, 0);
      for(int i = 1; i <= n; i++){
        cout << depth[i] << ' ';
      }
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
