#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> G[N];
int vis[N], disc[N], low[N], tme = 1;
vector<pair<int, int>> bridge;
set<int> art_point;

void dfs(int cur, int par){
  vis[cur] = 1;
  disc[cur] = low[cur] = tme++;
  int child = 0;
  for(auto x : G[cur]){
    if(!vis[x]){
      dfs(x, cur);
      child++;
      low[cur] = min(low[cur], low[x]);
      if(low[x] > disc[cur]){
        bridge.push_back({cur, x});
      }
      if(par != 0 && low[x] >= disc[cur]){
       art_point.insert(cur);
      }
    }else if( x != par){
      low[cur] = min(low[cur], disc[x]);
    }
  }
  if( par == 0 && child > 1){
    art_point.insert(cur);
  }
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
    dfs(1, 0);

    for(auto x : art_point){
      cout << x << '\n';
    }

    for(auto x : bridge){
      cout << x.first << ' ' << x.second << '\n';
    }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}



//LatsTry Again
#include<bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> g[N];
vector<int> low(N, 0), dis(N, 0);
vector<bool> vis(N, false);
vector<pair<int, int>> bridges;
set<int> art_points;
int timer = 1;

void dfs(int cur, int par){
    vis[cur] = true;
    dis[cur] = low[cur] = timer++;
    int child = 0;
    for(auto x : g[cur]){
        if(!vis[x]){
            dfs(x, cur);
            child++;
            low[cur] = min(low[cur], low[x]);
            if(low[x] > dis[cur]){
                bridges.push_back({cur, x});
            }
            if(par != 0 && low[x] >= dis[cur]){
                art_points.insert(cur);
            }
         
        }else if ( x != par){
            low[cur] = min(low[cur], dis[x]);
        }
    }
    if(par == 0 && child > 1)art_points.insert(cur);
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
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
      }
      dfs(1, 0);
      cout << "Articulation Bridges " << '\n';
      for(auto x : bridges){
        cout << x.first << "-- >" << x.second << '\n';
      }
      cout << "Articulation Points " << '\n';
      for(auto x = art_points.begin(); x != art_points.end(); x ++){
         cout << *x << '\n';
      }
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}

//Using Map
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 9;
map<int, vector<int>> g;
map<int, bool> vis;
vector<int> dis(N), low(N);
int timer = 1; set<pair<int, int>> bridge;
set<int> art_point;

void dfs(int cur, int par) {
    vis[cur] = true;
    dis[cur] = low[cur] = timer++;
    int child = 0;
    for(auto x : g[cur]){
        if(!vis[x]){
            dfs(x, cur);
            low[cur] = min(low[cur], low[x]);
            if(low[x] > dis[cur] and cur != par){
                bridge.insert({cur, x});
            }
            if(low[x] >= dis[cur] and cur != par){
               art_point.insert(cur);
            }
            child++;
        }else if(x != par){
            low[cur] = min(low[cur], dis[x]);
        }
    }
    if(child > 1 and par == 0)art_point.insert(cur);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i, 0);
        }
    }
    for(auto x : art_point)cout << x << ' ';
    cout << '\n';
    for(auto x : bridge){
        cout << x.first << ' ' << x.second << '\n';
    }
    return 0;
}

