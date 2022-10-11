#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 9;
vector<int> g[N];
vector<int> C(N);


void dfs(int cur, int par, vector<int> &ans){
     if(C[cur]){
         bool disrespect = true;
         for(auto x : g[cur]){
             if(!C[x])disrespect = false;
         }
         if(disrespect)ans.push_back(cur);
     }
     for(auto x : g[cur]){
         if(x != par){
             dfs(x, cur, ans);
         }
     }
}

int32_t main(){
    int n, par;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int p, c;
        cin >> p >> c;
        if(p == -1)par = i;
        else g[p].push_back(i), C[i] = c;
    }
    vector<int> ans;
    dfs(par, 0, ans);
    if(ans.empty()){
        cout << "-1" << '\n';
    }else{
        sort(ans.begin(), ans.end());
        for(auto x : ans){
            cout << x << ' ';
        }
    }
    return 0;
}
