#include<bits/stdc++.h>
using namespace  std;
#define int long long int
const int N = 30;
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
    c.push_back(cur - 1);
    for(auto x : rev[cur]){
        if(!vis[x]){
            dfs1(x, c);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; bool line = false;
    while (cin >> n and n){
        vector<int> node;
        for(int i = 0; i < n; i++){
            vector<char> a(5);
            for(int j = 0; j < 5; j++){
                cin >> a[j];
                node.push_back(a[j] - 'A' + 1);
            }
            char ch;
            cin >> ch;
            node.push_back(ch - 'A' + 1);
            for(auto x : a){
                g[ch - 'A' + 1].push_back(x - 'A' + 1);
                rev[x - 'A' + 1].push_back(ch - 'A' + 1);
            }
        }
        sort(node.begin(), node.end());
        for(auto x : node){
            if(!vis[x]){
                dfs(x);
            }
        }
        reverse(order.begin(), order.end());
        vector<set<char>> CC(N, set<char> ()); int cc = 1;
        vis.assign(N, false);
        for(auto x : order){
            if(!vis[x]){
                vector<int> c;
                dfs1(x, c);
                for(auto xx : c){
                    CC[cc].insert(((char) (xx + 'A')));
                }
                cc += 1;
            }
        }
        vector<vector<char>> ans(N, vector<char> ());
        for(int i = 1; i < cc; i++){
            int ch = *CC[i].begin();
            for(auto x : CC[i]){
               ans[ch - 'A' + 1].push_back(x);
            }
        }
        if(line) cout << '\n'; line = true;
        for(int i = 1; i < N; i++){
            if(ans[i].empty())continue;
            cout << *ans[i].begin();
            for(auto it = ans[i].begin() + 1; it != ans[i].end(); it++){
                cout << ' ' << *it;
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
