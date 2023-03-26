#include<bits/stdc++.h>
using namespace  std;
const int N = 1e5 + 9;
int a[N];

int f(int i, int v){
    if(!v or i < 1) return 0;
    return f(i - 1, v - 1) + a[i];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cout << f(n, m) << '\n';
    return 0;
}
