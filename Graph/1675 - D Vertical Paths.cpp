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
      int n;
      cin >> n;
      vector<int> par(n + 1), leaf(n + 1, 0), vis(n + 1, 0);
      for(int i = 1; i <= n; i++){
         cin >> par[i];
         if(i == par[i]){
            par[i] = -1;
            continue;
         }
         leaf[par[i]] = 1;
      }
      vector<int> lf;
      for(int i = 1; i <= n; i++){
        if(!leaf[i])lf.push_back(i);
      }
      cout << lf.size() << '\n';
      for(auto x : lf){
         int cur = x; vector<int> path;
         while(cur != -1 and !vis[cur]){
            vis[cur] = 1;
            path.push_back(cur);
            cur = par[cur];
         }
         reverse(path.begin(), path.end());
         cout << path.size() << '\n';
         for(auto y : path){
            cout << y << ' ';
         }
         cout << '\n';
      }
       cout << '\n';
      }
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
