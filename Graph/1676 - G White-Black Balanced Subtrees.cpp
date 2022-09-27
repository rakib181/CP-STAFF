#include<bits/stdc++.h>
using namespace std;

const int N = 4005;
vector<int> g[N];
string s; int res;

int dfs(int cur){
    int sub = (s[cur] == 'B') ? -1 : 1;
    for(auto x : g[cur]){
        sub += dfs(x);
    }
    if(sub == 0)res++;
    return sub;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
      int n;
      cin >> n;
      for(int i = 1; i <= n; i++)g[i].clear();
      for(int i = 2; i <= n; i++){
          int x;
          cin >> x;
          g[x].push_back(i);
      }
      cin >> s;
      s = '#' + s;
      res = 0;
      dfs(1);
      cout << res << '\n';
    }
    return 0;
}
