#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--){
        cout << "Case " << cs++ << ": ";
        int n;
        cin >> n;
        vector<int> ar(n);
        for(int i = 0; i < n; i++){
            cin >> ar[i];
        }
        sort(ar.begin(), ar.end());
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int sum = ar[i] + ar[j];
                auto ind = upper_bound(ar.begin(), ar.end(), sum - 1) - ar.begin();
                ind--;
                if(ind > j){
                    cnt += (ind - j);
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
