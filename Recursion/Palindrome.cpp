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

// Another Way
#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool palindrome(string s){
    if((int) s.size() == 0 or (int) s.size() == 1)return true;
    if(s[0] == s[s.size() - 1]){
        return palindrome(s.substr(1, s.size() - 2));
    }
    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    getline(cin, s);
    cout << palindrome(s) << '\n';
    return 0;
}
