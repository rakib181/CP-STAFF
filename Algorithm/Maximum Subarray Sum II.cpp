#include<bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> prefix (n + 2, 0);
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        prefix[i] = prefix[i - 1] + x;
    }
    multiset<int> ms; int ans = LONG_LONG_MIN;
    for(int i = a; i <= n; i++){
        if(i > b)ms.erase(ms.find(prefix[i - b - 1]));
        ms.insert(prefix[i - a]);
        ans = max(ans, prefix[i] - *ms.begin());
    }
    cout << ans << '\n';
    return 0;
}
