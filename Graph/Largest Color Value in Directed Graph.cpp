#include<bits/stdc++.h>
using namespace std;

int largestPathValue(string colors, vector<vector<int>> edges) {
    int n = colors.size();
    vector<int> g[n + 1];
    vector<vector<int>> cnt(n + 1, vector<int> (26, 0));
    vector<int> in(n + 1, 0);
    for(int i = 0; i < (int) edges.size(); i++){
       int u = edges[i][0], v = edges[i][1];
       g[u].push_back(v);
       in[v]++;
    }
    int ans = 0;
    queue<int> q;
    vector<int> top;
    for(int i = 0; i < n; i++){
      if(!in[i])q.push(i), cnt[i][colors[i] - 'a'] = 1;
    }

    while(!q.empty()){
      int node = q.front();
      q.pop();
      top.push_back(node);
      for(int i = 0; i < 26; i++){
         ans = max(ans, cnt[node][i]);
      }
      for(auto x : g[node]){
          for(int i = 0; i < 26; i++){
             cnt[x][i] = max(cnt[x][i], cnt[node][i] + ((colors[x] - 'a') == i));
          }
          if(--in[x] == 0)q.push(x);
      }
    }
    return top.size() == n ? ans : -1;
 }

int main(){
   int n = 5;
   string colors = "abaca";
   vector<vector<int>> edges = {
       {0,1},{0,2},{2,3},{3,4}
   };
   cout << largestPathValue(colors, edges) << '\n';
}
