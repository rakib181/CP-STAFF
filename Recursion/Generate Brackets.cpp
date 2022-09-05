#include <bits/stdc++.h>
using namespace std;

void generate_brac(string s, int n, int idx, int open, int close){
    if(idx == 2 * n){
        cout << s << '\n';
        return;
    }

    if(open < n){
        generate_brac(s + '(', n, idx + 1, open + 1, close);
    }
    if(close < open){
        generate_brac(s + ')', n, idx + 1, open, close + 1);
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string output;
    generate_brac(output, n, 0, 0, 0);
    return 0;
}
