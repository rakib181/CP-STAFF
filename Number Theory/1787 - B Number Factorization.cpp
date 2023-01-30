#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 505;
pair<int, int> s[N];
vector<int> d(N);

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        int n, l = 0, cnt = 0;
        cin >> n;
        while (n % 2 == 0){
             cnt++;
             n /= 2;
        }
        if(cnt) s[++l] = {cnt, 2};
        for(int i = 3; i * i <= n; i += 2){
            if(n % i == 0){
                 cnt = 0;
                while (n % i == 0){
                    cnt++;
                    n /= i;
                }
                s[++l] = {cnt, i};
            }
        }
        if(n > 1) s[++l] = {1, n};
        sort(s + 1, s + l + 1);
        d[l + 1] = 1;
        for(int i = l; i > 0; i--){
            d[i] = d[i + 1] * s[i].second;
        }
        int ans = 0;
        for(int i = 1; i <= l; i++){
            if(s[i].first != s[i - 1].first) ans += d[i] * (s[i].first - s[i - 1].first);
        }
        cout << ans << '\n';
    }
    return 0;
}
