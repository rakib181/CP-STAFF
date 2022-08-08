#include<bits/stdc++.h>
using namespace std;
int ans = INT_MIN;
void rec(vector<int>& ar, int i, int n){
    if(i == n)return;
    ans = max(ans, ar[i]);
    cout << ans << ' ';
    rec(ar, i + 1, n);
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int i = 0; i < n; i++)cin >> ar[i];
    rec(ar, 0, n);
    return 0;
}
