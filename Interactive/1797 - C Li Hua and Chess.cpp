#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int ask(int x, int y){
   cout << "? " << x << ' ' << y << endl;
   int d;
   cin >> d;
   return d;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int k = ask(1, 1);
        int x = min(k + 1, n), y = min(k + 1, m);
        int p = ask(1, y);
        int q = ask(x, 1);
        if(p == q){
            cout << "! " << x << ' ' << x << endl;
        }else if(p < q){
            cout << "! " << p + 1 << ' ' << y << endl;
        }else{
            cout << "! " << x << ' ' << q + 1 << endl;
        }
    }
    return 0;
}
