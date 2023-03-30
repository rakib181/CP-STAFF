#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 9;
int a[N], n, q;

int solve(int l, int r, int x){
    int ans = 0;
    while(l <= r){
        int m = (l + r) >> 1;
        if(a[m] <= x){
            ans = m;
            l = m + 1;
        }else r = m - 1;
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    cin >> q;
    while (q--) {
       int l, r;
       cin >> l >> r;
       cout << solve(1, n, r) - solve(1, n, l - 1) << '\n';
    }
    return 0;
}
