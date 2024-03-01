#include<bits/stdc++.h>
using namespace std;
using ll = long long;

char ask(int a, int b, int c, int d){
    cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << endl;
    char res; cin >> res;
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int mx = 0;
        for(int i = 1; i < n; i++){
            if(ask(i, i, mx, mx) == '>'){
                mx = i;
            }
        }
        int mn = 0;
        for(int i = 1; i < n; i++){
            char res = ask(i, mx, mn, mx);
            if(res == '>' or (res == '=' and ask(i, i, mn, mn) == '<')){
                mn = i;
            }
        }
        cout << "! " << mn << ' ' << mx << endl;
    }
    return 0;
}
