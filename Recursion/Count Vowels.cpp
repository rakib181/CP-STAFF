#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
int letTry(string s, int i, int n){
    if(i == n)return 1;
    if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] =='u'
    || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] =='U')cnt++;

    letTry(s, i + 1, n);
    return cnt;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
     string s;
    getline(cin, s);
    cout << letTry(s, 0, s.size()) << '\n';
    return 0;
}
