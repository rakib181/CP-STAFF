#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 2e5 + 9;
vector<int> g[N], d1(N), d2(N);
vector<bool> vis(N);

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(i + a[i] <= n){
            g[i + a[i]].push_back(i);
        }
        if(i - a[i] >= 1){
            g[i - a[i]].push_back(i);
        }
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(a[i] & 1)q.push(i), vis[i] = true;
    }
    while (!q.empty()){
        int node = q.front();
        q.pop();
        for(auto x : g[node]){
            if(!vis[x]){
                d1[x] = d1[node] + 1;
                vis[x] = true;
                q.push(x);
            }
        }
    }
    vis.assign(N, false);
    for(int i = 1; i <= n; i++){
        if(!(a[i] & 1))q.push(i), vis[i] = true;
    }
    while (!q.empty()){
        int node = q.front();
        q.pop();
        for(auto x : g[node]){
            if(!vis[x]){
                d2[x] = d2[node] + 1;
                vis[x] = true;
                q.push(x);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(d1[i] + d2[i] == 0)cout << "-1" << ' ';
        else cout << d1[i] + d2[i] << ' ';
    }
    return 0;
}
