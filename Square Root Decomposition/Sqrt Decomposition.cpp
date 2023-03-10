#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    int sq = (int) sqrt(n) + 1;
    vector<int> a(n), b(sq);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i / sq] += a[i];
    }
    while (q--){
        int type;
        cin >> type;
        if(type) {
            int l, r, s = 0;
            cin >> l >> r;
            while (l < r) {
                if (l % sq == 0 and l + sq - 1 <= r) {
                    s += b[l / sq];
                    l += sq;
                } else {
                    s += a[l];
                    l++;
                }
            }
            cout << s << '\n';
        }else{
            int i, x;
            cin >> i >> x;
            b[i / sq] = (x - a[i]);
            a[i] = x;
        }
    }
    return 0;
}
