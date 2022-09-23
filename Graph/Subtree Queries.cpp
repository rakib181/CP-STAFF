#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
vector<int> subtree_sum(N, 0), even(N, 0);

void dfs(int cur, int par){
    subtree_sum[cur] += cur;
    if(!(cur & 1))even[cur]++;
    for(auto x : g[cur]){
        if(x != par){
            dfs(x, cur);
            subtree_sum[cur] += subtree_sum[x];
            even[cur] += even[x];
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
        cout << subtree_sum[i] << ' ';
      }
      cout << '\n';
      for(int i = 1; i <= n; i++){
        cout << even[i] << ' ';
      }
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
