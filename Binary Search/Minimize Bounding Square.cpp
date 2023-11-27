#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
const ll inf = 2e18 + 9;
int n, x[N], y[N];
ll prefix[2][N], k;

ll get(int l, int r, int id){
    return prefix[id][r] - prefix[id][l - 1];
}

ll f(const int *a, int m, int id){
    ll ans = inf;
    for(int l = 1, r = 1; l <= n; l++){
        while(r <= n and a[l] + m >= a[r]){
            r += 1;
        }
        ll c = 1LL * (l - 1) * a[l] - get(1, l - 1, id);
        if(r <= n){
            c += get(r ,n, id) - 1LL * (n - r + 1) * (a[l] + m);
        }
        ans = min(ans, c);
    }
    for(int r = n, l = n; r >= 1; r--){
        while(l >= 1 and a[r] - m <= a[l]){
            l -= 1;
        }
        ll c = get(r + 1, n, id) - 1LL * (n - r) * a[r];
        if(l >= 1){
            c += 1LL * l * (a[r] - m) - get(1, l, id);
        }
        ans = min(ans, c);
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);
    for(int i = 1; i <= n; i++){
        prefix[0][i] = prefix[0][i - 1] + x[i];
        prefix[1][i] = prefix[1][i - 1] + y[i];
    }
    int l = 0, r = 1e9, ans = 0;
    while(l <= r){
        int m = (l + r) >> 1;
        if(f(x, m, 0) + f(y, m, 1) <= k){
            ans = m;
            r = m - 1;
        }else l = m + 1;
    }
    cout << ans << '\n';
    return 0;
}
