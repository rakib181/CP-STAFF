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
//Another Way
#include<bits/stdc++.h>
using namespace std;
#define int long long int

string DTB(int x, string res){
    if(x == 0)return res;
    if(x & 1) res = "1" + res;
    else res = "0" + res;
    return DTB(x / 2, res);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << DTB(n, "") << '\n';
    return 0;
}
