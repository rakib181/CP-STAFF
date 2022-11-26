#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s;
    cin >> n >> s;
    vector<int> ar(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
    }
    int ans = -1, sum = 0, l = 1;
    for(int r = 1; r <= n; r++){
        sum += ar[r];
        while (sum > s){
            sum -= ar[l++];
        }
        ans = max <long long> (ans, r - l + 1);
    }
    if(ans != -1)cout << ans << '\n';
    else cout << "0" << '\n';

    return 0;
}
