#include<bits/stdc++.h>
using namespace std;

#define long long long int

const int N = 1e5 + 1;
double f[N];

void cal(){
    f[0] = log(1), f[1] = log(1);
    for(int i = 2; i < N; i++){
        f[i] = f[i - 1] + log(i);
    }
}



signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> a(m + 1); int sum = 0;
    for(int i = 1; i <= m; i++)cin >> a[i], sum += a[i];
    if(sum < n){
        cout << "-1\n";
        return 0;
    }
    n--;
    if(n > sum - a[h]){
        cout << "1\n";
        return 0;
    }
    int s_not_h = sum - a[h];
    int s_h = sum - 1;
    double ans = 1.0 - exp(f[s_not_h] - f[n] - f[s_not_h - n] - f[s_h] + f[n] + f[s_h - n]);
    cout << fixed << setprecision(6) << ans << '\n';
    return 0;
}
