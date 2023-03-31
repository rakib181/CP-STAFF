#include<bits/stdc++.h>
using namespace std;
vector<bool> ans;

void solve(int n){
    if(n == 3){
        ans.push_back(true);
        return;
    }
    int x = n / 2;
    if(x % 2 == 0)x += 1;
    if(2 * x + 1 == n){
        ans.push_back(true);
    }else{
        ans.push_back(false);
    }
    solve(x);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
       int n;
       cin >> n;
       if(!(n & 1)){
           cout << "-1" << '\n';
           continue;
       }
       ans.clear();
       if(n == 3){
           cout << "1\n" << "2\n";
           continue;
       }
        solve(n);
        reverse(ans.begin(), ans.end());
        cout << (int) ans.size() << '\n';
        for(auto && an : ans){
            if(an)cout << "2 ";
            else cout << "1 ";
        }
       cout << '\n';
    }
    return 0;
}
