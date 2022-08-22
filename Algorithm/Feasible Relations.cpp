#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
int parent[N]; int Rank[N];

void makeset(){
    for(int i = 1; i < N; i++){
        parent[i] = i;
        Rank[i] = 1;
    }
}

int find(int v){
    if(parent[v] == v)return v;

    return parent[v] = find(parent[v]);
}

void make_union(int u, int v){
    u = find(u), v = find(v);

    if(u == v)return;

    if(Rank[u] > Rank[v]){
        parent[v] = u;
    }else if(Rank[v] > Rank[u]){
        parent[u] = v;
    }else{
        parent[u] = v;
        Rank[u]++;
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
      int tt;
      cin >> tt;
      while(tt--){
      for(int i = 1; i < N; i++)parent[i] = 0, Rank[i] = 0;
      makeset();
      int n, k;
      cin >> n >> k;
      vector<pair<int, int>> query;
      while(k--){
      int a, b; string s;
      cin >> a >> s >> b;
      if(s.size() == 1){
        make_union(a, b);
      }else{
        query.push_back({a, b});
      }
     }
     bool ok = true;
     for(auto x : query){
       if(find(x.first) == find(x.second)){
        ok = false;
        break;
       }
     }
     if(ok)cout << "YES" << '\n';
     else cout << "NO" << '\n';
     }
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
