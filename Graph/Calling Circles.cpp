#include<bits/stdc++.h>
using namespace  std;
#define int long long int
const int N = 1e5 + 9;
vector<int> g[N], rev[N], order;
vector<bool> vis(N);

void dfs(int cur){
    vis[cur] = true;
    for(auto x : g[cur]){
        if(!vis[x]){
            dfs(x);
        }
    }
    order.push_back(cur);
}

void dfs1(int cur, vector<int> &c){
    vis[cur] = true;
    c.push_back(cur);
    for(auto x : rev[cur]){
        if(!vis[x]){
            dfs1(x, c);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, cs = 1;
    while (cin >> n >> m and (n and m)){
        cout << "Calling circles for data set " << cs++ << ":\n";
        map<string, int> mp;
        map<int, string> mpp;
        cin.ignore(); int id = 1;
        for(int i = 0; i < m; i++){
            string s, ss;
            cin >> s >> ss;
            if(!mp[s]){
                mpp[id] = s;
                mp[s] = id++;
            }
            if(!mp[ss]){
                mpp[id] = ss;
                mp[ss] = id++;
            }
            g[mp[s]].push_back(mp[ss]);
            rev[mp[ss]].push_back(mp[s]);
        }
        for(int i = 1; i < id; i++){
            if(!vis[i]){
                dfs(i);
            }
        }
        reverse(order.begin(), order.end());
        vis.assign(n + 1, false); vector<vector<string>> cc (id, vector<string> ()); int con = 1;
        for(auto x : order){
             if(!vis[x]){
                 vector<int> c;
                 dfs1(x, c);
                 for(auto xx : c){
                     cc[con].push_back(mpp[xx]);
                 }
                 con += 1;
             }
        }
        for(int i = 1; i < con; i++){
            for(int j = 0; j < (int) cc[i].size(); j++){
                 cout << cc[i][j];
                 if(j != (int) cc[i].size() - 1) cout << ", ";
            }
            cout << '\n';
        }
        for(int i = 0; i < N; i++){
            g[i].clear();
            rev[i].clear();
            vis[i] = false;
        }
        order.clear();
    }
    return 0;
}
