#include <bits/stdc++.h>
using namespace std;

string rev(string &s, string c){
   if(s.size() == 0)return c;
   c += s.back();
   s.pop_back();
   return rev(s, c);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
     string s;
     cin >> s;
     cout << rev(s, "");
    return 0;
}
