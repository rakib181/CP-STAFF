#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1005, MX = 1e7;
int t[N], z[N], y[N], balloons[N], required_balloons, n;

bool good(int time){
    int total_balloons = 0;
    int remaining = required_balloons;
    for(int i = 1; i <= n; i++){
        int block_time = t[i] * z[i] + y[i];
        int count_blocks = time / block_time;
        int cur_balloons = z[i] * count_blocks;
        int partial = time % block_time;
        cur_balloons += min(z[i], partial / t[i]);
        total_balloons += cur_balloons;
        balloons[i] = min(cur_balloons, remaining);
        remaining -= balloons[i];
    }
    return total_balloons >= required_balloons;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> required_balloons >> n;
    for(int i = 1; i <= n; i++){
        cin >> t[i] >> z[i] >> y[i];
    }
    int l = 0, r = MX, ans = 0;
    while (l <= r){
        int m = (l + r) >> 1;
        if(good(m)){
            ans = m;
            r = m - 1;
        }else l = m + 1;
    }
    good(ans);
    cout << ans << '\n';
    for(int i = 1; i <= n; i++){
        cout << balloons[i] << ' ';
    }
    cout << '\n';
    return 0;
}
