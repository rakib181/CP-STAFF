#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    mt19937 mt(0);
    int n, q;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    vector<unsigned int> pa(n + 1, 0), pb(n + 1, 0);
    map<int, unsigned int> hashVal;
    set<int> sa, sb;
    for(int i = 1; i <= n; i++){
        if(sa.count(a[i])){
            a[i] = 0;
        }else{
            sa.insert(a[i]);
        }
    }
    for(int i = 1; i <= n; i++){
        if(sb.count(b[i])){
            b[i] = 0;
        }else{
            sb.insert(b[i]);
        }
    }
    for(int i = 1; i <= n; i++){
        if(a[i] != 0 and !hashVal[a[i]]){
            hashVal[a[i]] = mt();
        }
        if(b[i] != 0 and !hashVal[b[i]]){
            hashVal[b[i]] = mt();
        }
    }
    for(int i = 1; i <= n; i++){
        pa[i] = pa[i - 1];
        pb[i] = pb[i - 1];
        if(hashVal[a[i]]){
            pa[i] ^= hashVal[a[i]];
        }
        if(hashVal[b[i]]){
            pb[i] ^= hashVal[b[i]];
        }
    }
    cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;
        if(pa[x] == pb[y])cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
