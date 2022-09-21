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
