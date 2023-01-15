#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int l = 0, r = 0, ans = 0;
    while (r < n){
        if(a[r] - a[l] > d){
            ans += (n - r);
            while (l < r and a[r] - a[l] > d){
                l++;
                if(a[r] - a[l] > d){
                    ans += n - r;
                }
            }
        }
        r++;
    }
    cout << ans << '\n';
    return 0;
}
