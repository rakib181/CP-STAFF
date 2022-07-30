#include<bits/stdc++.h>
using namespace std;

void manachars(string s){
    int c = 0, r = 0, n = s.size(), maxidx = 0, centreidx = 0;
    vector<int> lps(n + 1, 0);
    for(int i = 0; i < n; i++){
        int mirror = 2 * c - i;
        if(r > i){
            lps[i] = min(r - i, lps[mirror]);
        }
        int idx1 = i + (lps[i] + 1), idx2 = i - (lps[i] + 1);
        while(idx1 < n && idx2 >= 0 && s[idx1] == s[idx2]){
            lps[i]++;
            idx1++;
            idx2--;
        }
        if(i + lps[i] > r){
            c = i;
            r = i + lps[i];
        }
    }
    for(int i = 0; i < n; i++){
     if(lps[i] > maxidx){
         maxidx = lps[i];
         centreidx = i;
     }
    }
   string k = s.substr(centreidx - maxidx + 1, 2 * maxidx);
    for(int i = 0; i < k.size(); i++){
        if(k[i] != '#'){
            cout << k[i];
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    auto extend = [&](string s){
        string ex;
        int n = s.size();
        for(int i = 0; i < n; i++){
            ex += "#" + s.substr(i, 1);
        }
        ex += "#";
        return ex;
    };
    string ss = extend(s);
    manachars(ss);
    return 0;
}
