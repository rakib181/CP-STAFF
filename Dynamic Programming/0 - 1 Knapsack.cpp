#include <bits/stdc++.h>
using namespace std;

const int N = 105;
#define int long long
int n, w, W[N], V[N];

int knapsack(int i, int weight){
    if(i == n)return 0;
    int ans = 0;
    if(weight + W[i] <= w)ans = max(ans, knapsack(i + 1, weight + W[i]) + V[i]);
    ans = max(ans, knapsack(i + 1, weight));
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> w;
    for(int i = 0; i < n; i++){
        cin >> W[i] >> V[i];
    }
    cout << knapsack(0, 0) << '\n';
    return 0;
}
