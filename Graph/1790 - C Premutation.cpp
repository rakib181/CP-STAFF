#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 105;
vector<int> g[N]; vector<int> ind(N);

vector<int> top_sort(int n){
    queue<int> q; vector<int> a;
    for(int i = 0; i < n; i++){
        if(!ind[i])q.push(i);
    }
    while (!q.empty()){
        int node = q.front();
        q.pop();
         a.push_back(node);
        for(auto x : g[node]){
            if(--ind[x] == 0){
                q.push(x);
            }
        }
    }
    return a;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        for(int i = 0; i < N; i++){
            g[i].clear();
            ind[i] = 0;
        }
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            vector<int> a(n - 1);
            for(int j = 0; j < n - 1; j++){
                cin >> a[j];
                a[j]--;
            }
            for(int j = 0; j < n - 2; j++){
                g[a[j]].emplace_back(a[j + 1]);
            }
        }
        for(int i = 0; i < n; i++){
            for(auto x : g[i]){
                ind[x]++;
            }
        }
        auto v = top_sort(n);
        for(auto x : v){
            cout << x + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}
