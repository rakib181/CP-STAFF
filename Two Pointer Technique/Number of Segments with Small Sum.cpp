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
    int ans = 0, sum = 0, l = 1;
    for(int r = 1; r <= n; r++){
        sum += ar[r];
        while (sum > s){
            sum -= ar[l++];
        }
        ans += (r - l + 1);
    }
    cout << ans << '\n';

    return 0;
}
