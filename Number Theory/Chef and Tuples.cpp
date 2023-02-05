#include<bits/stdc++.h>
using namespace std;
#define  int long long int

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        vector<int> div;
        for(int i = 1; i * i <= n; i++){
            if(n % i == 0){
                div.push_back(i);
                if(i != n / i){
                    div.push_back(n / i);
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < (int) div.size(); i++){
            for(int j = 0; j < (int) div.size(); j++){
                if(div[i] <= a and div[j] <= b and !(n % (div[i] * div[j])) and (n / (div[i] * div[j])) <= c){
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}

