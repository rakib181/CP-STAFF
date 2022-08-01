#include <bits/stdc++.h>
using namespace std;


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, pattern;
    cin >> s >> pattern;
    int n = pattern.size();
    vector<int> lps(n + 1);
    auto _lps = [&](string s){
        int i = 0, j = 1, idx = 1;
        lps[0] = 0;
        for( ;s[j];  ){
            if(s[i] == s[j]){
                lps[idx++] = i + 1;
                i++, j++;
            }else{
                if(i != 0)i = lps[i - 1];
                else j++, lps[idx++] = 0;
            }
        }
    };
    _lps(pattern);
     int i = 0, j = 0, cnt = 0;
     while(i < s.size()){
         if(s[i] == pattern[j]){
             i++, j++;
         }else{
             if(j != 0)j = lps[j - 1];
             else i++;
         }
         if(j == pattern.size()){
            cnt++;
         }
     }
   cout << cnt << '\n';
    return 0;
}
