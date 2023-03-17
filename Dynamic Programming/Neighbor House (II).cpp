#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e3 + 9;
int dp1[N], dp2[N];

int cal_1(int i, vector<int> &a){
    if(i < 2)return 0;
    if(dp1[i] != -1)return dp1[i];
    return dp1[i] = max(cal_1(i - 1, a), cal_1(i - 2, a) + a[i]);
}
int cal_2(int i, vector<int> &a){
    if(i < 1)return 0;
    if(dp2[i] != -1)return dp2[i];
    return dp2[i] = max(cal_2(i - 1, a), cal_2(i - 2, a) + a[i]);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--) {
        cout << "Case " << cs++ << ": ";
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        memset(dp1, -1, sizeof dp1);
        memset(dp2, -1, sizeof dp2);
        cal_1(n, a);
        cal_2(n - 1, a);
        cout << max(dp1[n], dp2[n - 1]) << '\n';
    }
    return 0;
}
