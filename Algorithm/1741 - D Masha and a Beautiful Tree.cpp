#include<bits/stdc++.h>
using namespace  std;
#define int long long int
const int N = 3e5 + 9;
int a[N];

int solve(int l, int r){
    if(l < r){
        int m = (l + r) >> 1, cnt = 0;
        int s1 = solve(l, m);
        int s2 = solve(m + 1, r);
        int c1 = *max_element(a + l, a + m);
        int c2 = *max_element(a + m + 1, a + r);
        if(c1 > c2){
            cnt += 1;
            int i = l, d = m, j = m + 1;
            while (i <= d){
                swap(a[i++], a[j++]);
            }
        }
        return s1 + s2 + cnt;
    }
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
       int n;
       cin >> n;
       for(int i = 1; i <= n; i++){
           cin >> a[i];
       }
       int ans = solve(1, n);
       if(is_sorted(a + 1, a + n)){
           cout << ans << '\n';
       }else cout << "-1" << '\n';
    }
    return 0;
}
