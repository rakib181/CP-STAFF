#include<bits/stdc++.h>
using namespace std;
#define int long long int
string s;

void solve(int i, char c){
    if(i == 0)return;
    string t = s;
    s = s + c + t;
    solve(i - 1, (char) (c + 1));
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    solve(n, 'A');
    cout << s;
    return 0;
}
