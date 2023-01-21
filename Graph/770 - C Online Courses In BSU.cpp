#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 9;
vector<int> g[N], top;
vector<int> f(N);

bool f_cycle(int cur){
    f[cur] = 1;
    for(auto x : g[cur]){
        if(!f[x]){
            bool sub = f_cycle( x);
            if(sub)return true;
        }else if(f[x] == 1){
            return true;
        }
    }
    f[cur] = 2;
    return false;
}

void dfs(int cur){
    f[cur] = 1;
    for(auto x : g[cur]){
        if(!f[x]){
            dfs(x);
        }
    }
    top.push_back(cur);
}



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a (k);
    for(int i = 0; i < k; i++)cin >> a[i];
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        while (x--){
            int v;
            cin >> v;
            g[i].push_back(v);
        }
    }
    bool cycle = false;
    for(auto x : a){
        if(!f[x] and f_cycle(x)){
            cycle = true;
            break;
        }
    }
    for(int i = 0; i <= n; i++){
        f[i] = 0;
    }
    if(!cycle){
        for(auto x : a){
            if(!f[x]) dfs(x);
        }
        cout << (int) top.size() << '\n';
        for(auto x : top){
            cout << x << ' ';
        }
    }else{
       cout << "-1" << '\n';
    }

    return 0;
}
