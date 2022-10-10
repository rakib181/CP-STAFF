#include<bits/stdc++.h>
using namespace std;

int min_path_cost(int i, int j, vector<vector<int>> &ar, int n, int m, vector<vector<int>> &dp){
    if(i > n or j > m)return INT_MAX;
    if(i == n and j == m)return ar[i][j];
    if(dp[i][j] != -1)return dp[i][j];
    return dp[i][j] = ar[i][j] + min(min_path_cost(i + 1, j, ar, n, m, dp), min_path_cost(i, j + 1, ar, n, m, dp));
}
void path(int i, int j, vector<vector<int>> &ar, int n, int m, vector<vector<int>> &dp){
    if(i == n and j == m) {
        cout << "(" << i << "," << j << ")";
        return;
    }
    cout << "(" << i << "," << j << ")" << "-->";
    int right = min_path_cost(i, j + 1, ar, n, m, dp);
    int down = min_path_cost(i + 1, j, ar, n, m, dp);
    if(right <= down)path(i, j + 1, ar, n, m, dp);
    else path(i + 1, j, ar, n, m, dp);
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ar(n + 1, vector<int> (m + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> ar[i][j];
        }
    }
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
    cout << min_path_cost(1, 1,ar, n, m, dp) << '\n';
    path(1, 1, ar, n, m, dp);
    return 0;
}
