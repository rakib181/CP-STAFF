#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int ask(int x, int y){
    cout << "? " << x << ' ' << y << endl;
    int d;
    cin >> d;
    return d;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int d = ask(1, 1);
        int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
        if(d <= n - 1){
            x1 = d + 1;
            y1 = 1;
        }else{
            x1 = n;
            y1 = d - n + 2;
        }
        if(d <= m - 1){
            x2 = 1;
            y2 = d + 1;
        }else{
            x2 = d - m + 2;
            y2 = m;
        }
        int d1 = ask(x1, y1);
        int d2 = ask(x2, y2);
        x1 -= (d1 / 2);
        y1 += (d1 / 2);
        x2 += (d2 / 2);
        y2 -= (d2 / 2);
        if(ask(x1, y1) == 0){
            cout << "! " << x1 << ' ' << y1 << endl;
        }else{
            cout << "! " << x2 << ' ' << y2 << endl;
        }
    }
    return 0;
}
