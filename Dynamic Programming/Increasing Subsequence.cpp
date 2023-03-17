#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> dp;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if(it == dp.end())dp.push_back(x);
        else *it = x;
    }
    cout << (int) dp.size() << '\n';
    return 0;
}
