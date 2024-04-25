#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int ask(int l, int r){
    cout << "? " << l << ' ' << r << endl;
    int x;
    cin >> x;
    return x;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int x = ask(1, 3);
    int y = ask(2, 3);
    int z = ask(1, 2);
    a[1] = x - y;
    a[3] = x - z;
    a[2] = x - (a[1] + a[3]);
    int s = a[1] + a[2] + a[3];
    for(int i = 4; i <= n; i++){
        int v = ask(1, i);
        a[i] = v - s;
        s += a[i];
    }
    cout << "! ";
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
