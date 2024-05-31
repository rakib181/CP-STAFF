#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int count(int n, int k){
    int ans = ((n + 1) >> (k + 1)) << k;
    if((n + 1) & (1LL << k)){
        ans = ans + ((n + 1) & ((1 << k) - 1));
    }
    return ans;
}

int f(int l, int r){
    int ans = 0;
    for(int k = 30; k >= 0; k--){
        if(count(r, k) - count(l - 1, k) > 0){
            ans |= (1 << k);
        }
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int l = max(0, n - m), r = n + m;
        cout << f(l, r) << '\n';
    }
    return 0;
}
