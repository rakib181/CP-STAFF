#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    int cnt = 0, l = 1, r = n / 2;
    while (l <= n / 2){
        while (r <= n and a[r] - a[l] < k) r += 1;
        if(r != n + 1){
            cnt += 1;
            r += 1;
        }else{
            break;
        }
        l += 1;
    }
    cout << cnt << '\n';
    return 0;
}
