#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<string> str;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    for(int i = 0; i < 26; i++){
        s += char(i + 'a');
    }
    for(int i = 0; i < 26; i++){
        s += char(i + 'A');
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool possible = true;
        vector<int> z(n);
        string ans;
        for(int i = 0; i < n; i++){
            cin >> z[i];
            if(i == 0 and z[i]){
                possible = false;
            }
            if(z[i] >= n)possible = false;
            ans += s[i];
        }
        if(!possible){
            cout << "!\n";
            continue;
        }
        for(int i = 1; i < n; i++){
            if(z[i] > 0){
                for(int j = 0; j < z[i]; j++){
                    ans[i + j] = ans[j];
                }
            }
        }
        vector<int> new_z(n, 0);
        for(int i = 1; i < n; i++){
            int cnt = 0;
            while(cnt + i < n and ans[cnt + i] == ans[cnt]){
                new_z[i] += 1;
                cnt += 1;
            }
        }
        if(z == new_z)cout << ans << '\n';
        else cout << "!\n";
    }
    return 0;
}
