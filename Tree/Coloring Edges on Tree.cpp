#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 9;
vector<int> g[N], col(N);

signed main(){
     ios_base::sync_with_stdio(false);
     cin.tie(nullptr);
     int n;
     cin >> n; map<int, int> cnt; vector<int> e;
     for(int i = 0; i < n - 1; i++){
         int u, v;
         cin >> u >> v;
         g[u].push_back(v);
         e.push_back(v);
     }
     queue<int> q;
     q.push(1);
     col[1] = -1;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        int c = 1;
        for(auto x : g[node]){
               if(col[node] == c) c += 1;
               col[x] = c;
               cnt[c] += 1;
               c += 1;
               q.push(x);
        }
    }
    cout << (int) cnt.size() << '\n';
    for(auto i : e){
          cout << col[i] << '\n';
    }
     return 0;
}
