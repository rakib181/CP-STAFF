#include<bits/stdc++.h>
using namespace std;
#define int long long int
int disk, step, moves;

void solve(int d, char s, char m, char e){
    if(d == 0)return;
    solve(d - 1, s, e, m);
    moves += 1;
    if(moves == step){
        cout << d << " : " << s << " => " << e << '\n';
    }
    solve(d - 1, m, s, e);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        cin >> disk >> step;
        moves = 0;
        solve(disk, 'A', 'B', 'C');
    }
    return 0;
}
