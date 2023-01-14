#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 6e5 + 10, EX = 3e5;
vector<int> g[N], path(N, -1);

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
         int x;
         cin >> x;
         for(int ii = 2; ii * ii <= x; ii++){
              if(x % ii == 0){
                  g[i].push_back(EX + ii);
                  g[EX + ii].push_back(i);
              }
             while (x % ii == 0) x /= ii;
         }
         if(x > 1){
             g[i].push_back(EX + x);
             g[EX + x].push_back(i);
         }
    }
    int s, t;
    cin >> s >> t;
    queue<int> q;
    q.push(s);
    path[s] = 1;
    while (!q.empty()){
        auto node = q.front();
        q.pop();
        for(auto x : g[node]){
            if(path[x] == -1){
                path[x] = node;
                q.push(x);
            }
        }
    }
    if(path[t] == -1){
        cout << "-1" << '\n';
    }else{
        vector<int> ans;
        int cur = t;
        while (cur != s){
            ans.push_back(cur);
            cur = path[cur];
        }
        reverse(ans.begin(), ans.end());
        int sz = (int) ans.size();
        cout << sz / 2 + 1 << '\n' << s << ' ';
        for(int i = 1; i < sz; i += 2){
            cout << ans[i] << ' ';
        }
    }
    return 0;
}
