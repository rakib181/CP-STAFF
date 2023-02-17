#include<bits/stdc++.h>
using namespace std;
#define int long long int

void factorize(int n, map<int, int> &mp){
   for(auto x : {2, 3, 5}){
       while (n % x == 0){
           mp[x]++;
           n /= x;
       }
   }
    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (long long d = 7; d * d <= n; d += increments[i++]) {
        while (n % d == 0) {
            mp[d]++;
            n /= d;
        }
        if (i == 8)
            i = 0;
    }
    if (n > 1)mp[n]++;
}

signed main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   int tt;
   cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        map<int, int> mp;
        factorize(n, mp);
        int ans = 0;
        while (!mp.empty()){
            int mn = LONG_LONG_MAX;
            for(auto x : mp){
                mn = min(mn, x.second);
            }
            int cur = 1;
            vector<int>  bad;
            for(auto &x : mp){
                cur *= x.first;
                x.second -= mn;
                if(x.second == 0)bad.push_back(x.first);
            }
            ans += cur * mn;
            for(auto x : bad){
                mp.erase(mp.find(x));
            }
        }
        cout << ans << '\n';
    }
   return 0;
}
