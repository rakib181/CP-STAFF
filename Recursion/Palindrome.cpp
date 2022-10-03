#include <bits/stdc++.h>
using namespace std;

bool valid(char c){
    return isalpha(c) or isdigit(c);
}

bool palindrome(string &s, int i, int n){
    if(i > n)return true;
    if(!valid(s[i])){
        return palindrome(s, i + 1, n);
    }
    if(!valid(s[n])){
        return palindrome(s, i, n - 1);
    }
    if(s[i] == s[n]){
        return palindrome(s, i + 1, n - 1);
    }
    return false;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
     string s;
     getline(cin, s);
     cout << palindrome(s, 0, s.size() - 1);
    return 0;
}
