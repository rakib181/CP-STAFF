#include<bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1, vector<int> (n + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> graph[i][j];
        }
    }
    vector<int> del_order(n + 1);
    for(int i = 1; i <= n; i++)cin >> del_order[i];
    reverse(del_order.begin() + 1, del_order.end());
    vector<int> ans;
    for(int k = 1; k <= n; k++){
        int k_v = del_order[k];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(graph[i][j] > graph[i][k_v] + graph[k_v][j]){
                    graph[i][j] = graph[i][k_v] + graph[k_v][j];
                }
            }
        }
        int sum = 0;
        for(int i = 1; i <= k; i++){
            for(int j = 1; j <= k; j++){
                sum += graph[del_order[i]][del_order[j]];
            }
        }
        ans.push_back(sum);
    }
    reverse(ans.begin(), ans.end());
    for(auto x: ans){
        cout << x << ' ';
    }
    return 0;
}
