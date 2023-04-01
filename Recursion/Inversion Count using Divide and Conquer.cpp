#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 2e5 + 9;
int a[N];

int solve(int l, int r){
    if(l < r){
        int m = (l + r) >> 1;
        int ans = solve(l, m);
        ans += solve(m + 1, r);
        vector<int> t;
        for(int i = m + 1; i <= r; i++){
            t.push_back(a[i]);
        }
        sort(t.begin(), t.end());
        for(int i = l; i <= m; i++){
            ans += (lower_bound(t.begin(), t.end(), a[i]) - t.begin());
        }
        return ans;
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
        cout << solve(1, n) << '\n';
    }
    return 0;
}
