#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1), prefix(n + 2, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        prefix[i] += prefix[i - 1] + a[i];
    }
    int t_sum = prefix[n];
    if(t_sum % 3){
        cout << "0" << '\n';
    }else{
        int sum = t_sum / 3;
        int tot = 0, cnt = 0;
        for(int i = n - 1; i >= 1; i--){
            if(prefix[i] == sum){
                tot += cnt;
            }
            if(prefix[i] == 2 * sum){
                cnt += 1;
            }
        }
        cout << tot << '\n';
    }
    return 0;
}
