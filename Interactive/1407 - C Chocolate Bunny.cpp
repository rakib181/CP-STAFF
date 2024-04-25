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
    vector<int> ans(n + 1, 0);
    int x = 1;
    for(int i = 2; i <= n; i++){
        int u = ask(x, i);
        int v = ask(i, x);
        if(u > v){
            ans[x] = u;
            x = i;
        }else{
            ans[i] = v;
        }
    }
    ans[x] = n;
    cout << "! ";
    for(int i = 1; i <= n; i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}
