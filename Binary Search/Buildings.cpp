#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    auto possible = [&] (int x){
        int tmp = k;
        for(int i = 0; i < n; i++){
            if(a[i] < x)tmp -= (x - a[i]);
            if(tmp < 0)return false;
        }
        return true;
    };
    int l = 0, r = 1e12, ans = 0;
    while (l <= r){
        int m = (l + r) >> 1;
        if(possible(m)){
            ans = m;
            l = m + 1;
        }else r = m - 1;
    }
    cout << ans << '\n';
    return 0;
}
