#include <bits/stdc++.h>
using namespace std;

#define long long long


long ask(long l, long r){
    cout << "xor " << l << ' ' << r << endl;
    long ans;
    cin >> ans;
    return ans;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        long n;
        cin >> n;
        long val = ask(1, n);
        if(val == 0){
            long l = 1, r = n;
             for(int i = __lg(n) + 1; i >= 0; i--){
                 if(ask(min(n, (1LL << i)), n) > 0){
                     r = (1LL << i) - 1;
                     break;
                 }
             }
             long a = -1;
            while (l <= r){
                long m = (l + r) >> 1;
                if(ask(1, m) > 0){
                    a = m;
                    r = m - 1;
                }else{
                    l = m + 1;
                }
            }
            l = a + 1, r = n; long b = -1;
            while (l <= r){
                long m = (l + r) >> 1;
                if(ask(a + 1, m) > 0){
                    b = m;
                    r = m - 1;
                }else{
                    l = m + 1;
                }
            }
            cout << "ans " << a << ' ' << b << ' ' << (a ^ b) << endl;
        }else{
            long l = 1, r = n, a = -1;
            while (l <= r){
                long m = (l + r) >> 1;
                if(ask(1, m) > 0){
                    a = m;
                    r = m - 1;
                }else{
                    l = m + 1;
                }
            }
            l = a + 1, r = n; long b = -1;
            while (l <= r){
                long m = (l + r) >> 1;
                if(ask(a + 1, m) > 0){
                    b = m;
                    r = m - 1;
                }else{
                    l = m + 1;
                }
            }
            long c = (val ^ a ^ b);
            cout << "ans " << a << ' ' << b << ' ' << c << endl;
        }
    }
    return 0;
}
