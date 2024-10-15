#include<bits/stdc++.h>
using namespace std;
#define long long long

int ask(int i, int j){
    cout << "? " << i << ' ' << j << endl;
    int x;
    cin >> x;
    return x;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int ans = -1;
        for(int i = 1; i + 1 <= n; i += 2){
            if(ask(i, i + 1) != ask(i + 1, i)){
                int j = (i > 1 ? 1 : n);
                if(ask(i, j) != ask(j, i)){
                    ans = i;
                }else{
                    ans = i + 1;
                }
                break;
            }
        }
        if(ans == -1)ans = n;
        cout << "! " << ans << endl;
    }
    return 0;
}
