#include <bits/stdc++.h>
using namespace std;
#define int long long int

int digit(int n){
    int sum = 0;
    while (n){
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1);  set<int> segment;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(a[i] > 9) segment.insert(i);
        }
        while (q--){
            int type;
            cin >> type;
            if(type == 1){
                int l, r;
                cin >> l >> r; int track = l;
                while (!segment.empty()){
                    auto it = segment.lower_bound(track);
                    if(it == segment.end() or *it > r) break;
                    a[*it] = digit(a[*it]);
                    auto idx = *it;
                    segment.erase(it);
                    if(a[idx] > 9) segment.insert(idx);
                    track = idx + 1;
                }
            }else{
                int i;
                cin >> i;
                cout << a[i] << '\n';
            }
        }
    }
    return 0;
}
