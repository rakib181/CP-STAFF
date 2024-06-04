#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    mt19937 mt(0);
    int n, q;
    cin >> n;
    vector<int> a(n + 1), b(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        b[i] = i;
    }
    vector<unsigned int> pa(n + 1, 0), pb(n + 1, 0);
    map<int, unsigned int> hashVal;
    for(int i = 1; i <= n; i++){
        if(!hashVal[a[i]]){
            hashVal[a[i]] = mt();
        }
        if(!hashVal[b[i]]){
            hashVal[b[i]] = mt();
        }
    }
    for(int i = 1; i <= n; i++){
        pa[i] = pa[i - 1] ^ hashVal[a[i]];
        pb[i] = pb[i - 1] ^ hashVal[b[i]];

    }
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        if((pa[r] ^ pa[l - 1]) == pb[r - l + 1])cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
