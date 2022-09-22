#include<bits/stdc++.h>
using namespace std;

const int N = 30009;
vector<int> parent(N), sz(N);

void init(int n){
    for(int i = 0; i < n; i++){
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
    parent[v] = u;
    sz[u] += sz[v];
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
      while(cin >> n, cin >> m){
        if(!n and !m)break;
        init(n);
        for(int i = 0; i < m; i++){
            int k, last = -1;
            cin >> k;
            while(k--){
                int x;
                cin >> x;
               if(last != -1)m_union(last, x);
               last = x;
            }
        }
        int cnt = 0, par = find(0);
        for(int i = 0; i < n; i++){
            if(find(i) == par)cnt++;
        }
        cout << cnt << '\n';
      }
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
