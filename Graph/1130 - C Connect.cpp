#include<bits/stdc++.h>
using namespace std;


int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
vector<pair<int, int>> ok;
void dfs1(int i, int j, int n, vector<vector<char>> &ar){
     if(i < 1 || j < 1 || i > n || j > n || ar[i][j] != '0') return;
      ar[i][j] = '1';
      ok.push_back({i, j});
     for(int k = 0; k < 4; k++){
          dfs1(i + dx[k], j + dy[k], n, ar);
     }
}

int ans = INT_MAX;
void dfs(int i, int j, int n, vector<vector<char>> &ar){
     if(i < 1 || j < 1 || i > n || j > n || ar[i][j] != '0') return;
     ar[i][j] = '1';
     for(auto x : ok){
       ans = min(ans, (int) pow(abs(i - x.first), 2) + (int) pow(abs(j - x.second), 2));
     }
     for(int k = 0; k < 4; k++){
          dfs(i + dx[k], j + dy[k], n, ar);
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
       int r, c, rd, cd;
       cin >> r >> c >> rd >> cd;
       vector<vector<char>> ar(n + 1, vector<char> (n + 1));
       for(int i = 1; i <= n; i++){
          for(int j = 1; j <= n; j++){
               cin >> ar[i][j];
          }
       }
       dfs1(rd, cd, n, ar);
       dfs(r, c, n, ar);
       if(ans != INT_MAX) cout << ans << '\n';
       else cout << "0" << '\n';
       cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
       return 0;
}
