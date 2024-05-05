#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<string> str;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    str.emplace_back("a");
    int id = 1;
    for(char c = 'b'; c <= 'z'; c++){
        str.emplace_back(str[id - 1] + c + str[id - 1]);
        id += 1;
    }
    int t;
    cin >> t;
    while(t--){
        int k, j;
        cin >> k >> j;
        k -= 1;
        int cnt = 0;
        if(j == 0){
            cout << "0\n";
            continue;
        }
        while(cnt + j < (int) str[k].size() and str[k][cnt + j] == str[k][cnt]){
            cnt += 1;
        }
        cout << cnt << '\n';
    }
    return 0;
}
