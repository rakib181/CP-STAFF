#include<bits/stdc++.h>
using namespace std;
#define int long long int

string rev(string &s, int n){
    if(n < 0)return "";
    return s[n] + rev(s, n - 1);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    getline(cin, s);
    cout << rev(s, (int) s.size() - 1) << '\n';
    return 0;
}
