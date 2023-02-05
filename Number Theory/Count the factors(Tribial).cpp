#include<bits/stdc++.h>
using namespace std;
#define  int long long int

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n and n){
        int tmp = n, cnt = 0;
        int i = 2;
        if(tmp % i == 0){
            cnt++;
            while (tmp % i == 0){
                tmp /= i;
            }
        }
        for(i = 3; i * i <= tmp; i += 2){
            if(tmp % i == 0){
                cnt++;
                while (tmp % i == 0){
                    tmp /= i;
                }
            }
        }
        if(tmp > 1)cnt++;
        cout << n << " : " << cnt << '\n';
    }
    return 0;
}

