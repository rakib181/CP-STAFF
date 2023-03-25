#include<bits/stdc++.h>
using namespace  std;
#define int long long int
const int N = 1005 + 9;
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

void dfs1(int cur){
    vis[cur] = true;
    for(auto x : rev[cur]){
        if(!vis[x]){
            dfs1(x);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while (cin >> n >> m){
        if(!n and !m)break;
        map<string , int> mp; int id = 1;
        cin.ignore();
        for(int i = 0; i < n; i++){
            string s;
            getline(cin, s);
            if(!mp[s]){
                mp[s] = id++;
            }
        }
        for(int i = 0; i < m; i++){
            string s, ss;
            getline(cin, s);
            getline(cin, ss);
            g[mp[s]].push_back(mp[ss]);
            rev[mp[ss]].push_back(mp[s]);
        }
        for(int i = 1; i < id; i++){
            if(!vis[i]){
                dfs(i);
            }
        }
        reverse(order.begin(), order.end());
        vis.assign(N, false); int cc = 0;
        for(auto x : order){
            if(!vis[x]){
                cc += 1;
                dfs1(x);
            }
        }
        cout << cc << '\n';
        for(int i = 0; i < N; i++){
            g[i].clear();
            rev[i].clear();
            vis[i] = false;
        }
        order.clear();
    }
    return 0;
}
