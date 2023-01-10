#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--) {
        cout << "Case " << cs++ << ": ";
        double x, y, c;
        cin >> x >> y >> c;
        auto f = [&](double m){
            double  h1 = sqrt((x * x) - (m * m));
            double h2 = sqrt((y * y) - (m * m));
            return ((h1 * h2) / (h1 + h2));
        };
        double l = 0.0, r = min(x, y);
        for(int i = 0; i < 60; i++){
            double m = (l + r) / 2.0;
            if(f(m) <= c){
                r = m;
            }else l = m;
        }
        cout << fixed << setprecision(8) << l << '\n';
    }
    return 0;
}
