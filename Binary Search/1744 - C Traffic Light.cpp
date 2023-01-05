#include<bits/stdc++.h>
using namespace std;
#define int long long int


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
       int n; char c;
       cin >> n >> c;
       string s;
       cin >> s;
       s += s;
       auto possible = [&](int x){
           int cnt = 0;
           for(int i = 0; i < (int) s.size(); i++){
               if(s[i] == c){
                   int cc = 0;
                   while (i < (int) s.size() and s[i] != 'g'){
                       cc++, i++;
                   }
                   cnt = max(cnt, cc);
               }
           }
           return cnt >= x;
       };
       int l = 1, r = n, ans = 0;
        while (l <= r){
            int mid = (l + r) >> 1;
            if(possible(mid)){
                ans = mid;
                l = mid + 1;
            }else r = mid - 1;
        }
        cout << ans << '\n';
    }
    return 0;
}

