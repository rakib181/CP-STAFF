#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, pattern;
    cin >> s >> pattern;
    int n = pattern.size();
    pattern += '#' + s;
    vector<int> z(pattern.size(), 0);
    auto prefix_f = [&](string s){
        for(int i = 1, l = 0, r = 0; i < s.size(); i++){
            if(r >= i)z[i] = min(r - i + 1,z[i - l]);
            while(i + z[i] - 1 < s.size() && s[z[i]] == s[i + z[i]])z[i]++;
            if(i + z[i] - 1 >= r)l = i, r = i + z[i] - 1;
        }
    };
    prefix_f(pattern); int cnt = 0;
    for(auto x : z){
     if(x == n)cnt++;
    }
    cout << cnt << '\n';
    return 0;
}
