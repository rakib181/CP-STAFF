#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 7, P = 31, MOD = 1e9 + 7;
vector<int> pw(N);
void calc(){
    pw[0] = 1;
    for(int i = 1; i < N; i++){
        pw[i] = pw[i - 1] * P % MOD;
    }
}
set<int> container;
void hashing(string &s){
    int tot = 0;
    for(int i = 0; i < (int) s.size(); i++){
        int T =  (s[i] - 'a' + 1) * pw[i] % MOD;
        tot = tot + T % MOD;
    }
    container.insert(tot);
}
int cal(string &s){
    int tot = 0;
    for(int i = 0; i < (int) s.size(); i++){
       int T =  (s[i] - 'a' + 1) * pw[i] % MOD;
       tot = tot + T % MOD;
    }
    return tot;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    calc();
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        hashing(s);
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        if(container.find(cal(s)) != container.end()){
            cout << "yes" << '\n';
        }else cout << "no" << '\n';
    }
    return 0;
}
