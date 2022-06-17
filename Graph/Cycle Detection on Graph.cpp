#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> G[N];
int vis[N];
bool cycle = false;

void dfs(int cur, int par){
  vis[cur] = 1;
  for(auto x : G[cur]){
    if(!vis[x]){
      dfs(x, cur);
    }else if(x != par && vis[x]==1){
      cycle = true;
    }
  }
  vis[cur] = 2;
}

int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    #endif
    auto start=clock();
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
      G[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
      if(!vis[i]){
        dfs(i, 0);
      }
    }
    if(cycle)cout << "Cycle Found !" << '\n';
    else cout << "Cycle Not Found !" << '\n';
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
