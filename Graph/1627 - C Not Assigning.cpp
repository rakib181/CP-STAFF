#include<bits/stdc++.h>
using namespace std;

int32_t main(){
     ios_base::sync_with_stdio(0);
      cin.tie(0); 
      #ifndef ONLINE_JUDGE 
      freopen("input.txt","r",stdin); 
      freopen("output.txt","w",stdout); 
      #endif
      auto start=clock();
      int tt;
      cin >> tt;
      while(tt--){
      int n, src;
      cin >> n;
      vector<pair<int, int> > g[n];
      vector<int> deg(n, 0), bp(n - 1, 0);
      for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
        deg[u]++;
        deg[v]++;
      }
      int mx = *max_element(deg.begin(), deg.end());
      if(mx > 2)cout << "-1" << '\n';
      else {
        src = min_element(deg.begin(), deg.end()) - deg.begin();
        function<void(int, int, int c)> dfs = [&] (int cur, int par, int c) {
           for(auto x : g[cur]){
            if(x.first != par){
                bp[x.second] = c;
                dfs(x.first, cur, c ^ 1);
            }
           }
        };
        dfs(src, -1, 0);
        for(auto &x : bp){
            cout << x + 2 << ' ';
        }
        cout << '\n';
      }
     }
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
