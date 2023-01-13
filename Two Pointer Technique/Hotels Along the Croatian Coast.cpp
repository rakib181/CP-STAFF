#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int l = 0, cost = 0, ans = 0;
    for(int i = 0; i < n; i++){
        if(cost + a[i] <= m){
            cost += a[i];
        }else{
            while (cost + a[i] > m){
                cost -= a[l++];
            }
            cost += a[i];
        }
        ans = max(ans, cost);
    }
    cout << ans << '\n';
    return 0;
}
