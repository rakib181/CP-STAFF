#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    ll ans1 = 0, ans2 = 0, even = 0, odd = 0; int lst = 0;
    for(int i = 1, cnt = 1; i <= n; i++){
        int x;
        cin >> x;
        if(x < 0){
            if(cnt & 1){
                odd += (i - lst);
                ans1 += (i - odd);
                ans2 += odd;
            }else{
                even += (i - lst);
                ans1 += (i - even);
                ans2 += even;
            }
            lst = i;
            cnt += 1;
        }else{
           if(cnt & 1)  ans1 += (i - even), ans2 += even;
           else ans1 += (i - odd), ans2 += odd;
        }
    }
    cout << ans2 << ' ' << ans1 << '\n';
    return 0;
}