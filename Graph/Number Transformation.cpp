#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 1005;
vector<int> g[N];

void FACT(int x){
    int tmp = x, idx;
    for(int i = 2; i <= x; i++){
         idx = 0;
        while(tmp % i == 0){
            idx = i;
            tmp /= i;
        }
        if(idx)g[x].push_back(idx);
    }
    if(tmp > 1)g[x].push_back(tmp);
    if(idx == x)g[x].clear();
}

void PRECAL(){
    for(int i = 2; i < N; i++){
        FACT(i);
    }
}

int BFS(int s, int t){
    queue<int> q;
    vector<int> dis(N, -1);
    q.push(s);
    dis[s] = 0;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        for(auto x : g[node]){
            int tot = node + x;
            if(tot <= t and dis[tot] == -1){
                q.push(tot);
                dis[tot] = dis[node] + 1;
                if(tot == t)return dis[t];
            }
        }
    }
    return dis[t];
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    PRECAL();
    int tt, cs = 1;
    cin >> tt;
    while (tt--) {
        cout << "Case " << cs++ << ": ";
        int s, t;
        cin >> s >> t;
        cout << BFS(s, t) << '\n';
    }
    return 0;
}
