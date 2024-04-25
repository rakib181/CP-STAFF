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
    int n;
    cin >> n;
    vector<int> ans(n + 1);
    int x = ask(1, 2);
    int y = ask(1, 3);
    int z = ask(2, 3);
    ans[2] = abs((x - y + z)) / 2;
    ans[1] = abs(x - ans[2]);
    ans[3] = abs(y - ans[1]);
    for(int i = 4; i <= n; i++){
        int v = ask(1, i);
        ans[i] = abs(v - ans[1]);
    }
    cout << "! ";
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << '\n';
    return 0;
}
