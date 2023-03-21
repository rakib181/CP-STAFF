#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 2e5 + 9;
int P[N], S[N], PREFIX[N];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    int r = 0;
    for(int i = 0; i < n; i++){
        r += (a[i] * b[i]);
        P[i] = r;
    }
    r = 0;
    for(int i = n - 1; i >= 0; i--){
        r += (a[i] * b[i]);
        S[i] = r;
    }
    r = 0;
    for(int i = 0; i < n; i++){
        r += a[i];
        PREFIX[i] = r;
    }
    int ans = 0;
    for(int i = 0; i + k - 1 < n; i++){
        int cal = 0;
        if(i) cal += P[i - 1];
        cal += (PREFIX[i + k - 1] - PREFIX[i - 1]);
        cal += S[i + k];
        ans = max(ans, cal);
    }
    cout << ans << '\n';
    return 0;
}
