#include<bits/stdc++.h>
using namespace  std;
#define int long long int
const int N = 105;
int a[N], p[N];

void solve(int l, int r, int h){
    if(l <= r){
        int m = -1, mx = INT_MIN;
        for(int i = l; i <= r; i++){
            if(a[i] >= mx){
                mx = a[i];
                m = i;
            }
        }
        p[m] = h;
        solve(l, m - 1, h + 1);
        solve(m + 1, r, h + 1);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        solve(1, n, 0);
        for (int i = 1; i <= n; i++) {
            cout << p[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
