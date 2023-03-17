#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 3001; int n;
double dp[N][N]; bool vis[N][N];
vector<double> a;

double coin(int i, int h, int t){
    if(i == n + 1){
        if(h > t) return 1;
        else return 0;
    }
    if(vis[i][h])return dp[i][h];
    double ans = a[i] * coin(i + 1, h + 1, t);
    ans += (1 - a[i]) * coin(i + 1, h, t + 1);
    vis[i][h] = true;
    return dp[i][h] = ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    a.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cout << fixed << setprecision(10) << coin(1, 0, 0) << '\n';
    return 0;
}
