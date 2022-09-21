//DSU

#include<bits/stdc++.h>
using namespace std;

const int N = 5 * 1e5 + 9;
vector<int> parent(N, 0);
vector<int> sz(N, 0);

void init(int n){
  for(int i = 1; i <= n; i++){
    parent[i] = i;
    sz[i] = 1;
  }
}

int find(int v){
  if(parent[v] == v)return v;

  return parent[v] = find(parent[v]);
}

void m_union(int u, int v){
  u = find(u), v = find(v);
  if(u == v)return;

  if(sz[u] > sz[v])swap(u, v);
  parent[u] = v;
  sz[v] += sz[u];
}


int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0); 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    #endif
    auto start=clock();
    int n, m;
    cin >> n >> m;
    init(n);
    for(int i = 0; i < m; i++){
      int k;
      cin >> k; int lst = -1;
      for(int j = 0; j < k; j++){
         int x;
         cin >> x;
         if(lst != -1){
           m_union(lst, x);
         }
         lst = x;
      }
    }
    for(int i = 1; i <= n; i++)cout << sz[find(i)] << ' ';
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}


// DFS

#include<bits/stdc++.h>
using namespace std;

const int N = 5 * 1e5 + 9;
vector<int> g[N];
vector<int> col(N, 0);
vector<int> sz(N, 0);
int cc;

int dfs(int cur){
  if(col[cur])return 0;

  col[cur] = cc;

  int ans = 1;
  for(auto x : g[cur]){
    ans += dfs(x);
  }
  return ans;
}

int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0); 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    #endif
    auto start=clock();
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
      int k;
      cin >> k; int lst = -1;
      for(int j = 0; j < k; j++){
         int x;
         cin >> x;
         if(lst != -1){
           g[lst].push_back(x);
           g[x].push_back(lst);
         }
         lst = x;
      }
    }
    for(int i = 1; i <= n; i++){
        if(!col[i]){
          cc = i;
          sz[cc] = dfs(i);
        }
    }
    for(int i = 1; i <= n; i++){
      cout << sz[col[i]] << ' ';
    }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}

