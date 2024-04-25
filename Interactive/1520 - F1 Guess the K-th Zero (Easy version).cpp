#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int ask(int i, int j){
    cout << "? " << i << ' ' << j << endl;
    int x;
    cin >> x;
    return x;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    cin >> n >> t;
    int k;
    cin >> k;
    int l = 1, r = n, ans = -1;
    while(l <= r){
        int m = (l + r) >> 1;
        int s = ask(1, m);
        int z = m - s;
        if(z >= k){
            ans = m;
            r = m - 1;
        }else{
            l = m + 1;
        }
    }
    cout << "! " << ans << endl;
    return 0;
}
