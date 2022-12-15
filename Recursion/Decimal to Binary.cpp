#include<bits/stdc++.h>
using namespace std;
#define int long long int

void DTB(int x){
    if(x == 0)return;
    DTB(x / 2);
    if(x & 1)cout << 1;
    else cout << 0;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    DTB(n);
    return 0;
}
